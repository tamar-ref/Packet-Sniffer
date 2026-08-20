#include "../../../headers/printer/layer4/tcp.h"

void print_tcp(Tcp tcp)
{
       uint16_t data_offset = (tcp.data_offset_reserved_flags >> 12) & 0x0F;
       uint16_t reserved = (tcp.data_offset_reserved_flags >> 9) & 0x07;
       uint16_t flags = tcp.data_offset_reserved_flags & 0x01FF;

       uint8_t ns = (flags >> 8) & 1;
       uint8_t cwr = (flags >> 7) & 1;
       uint8_t ece = (flags >> 6) & 1;
       uint8_t urg = (flags >> 5) & 1;
       uint8_t ack = (flags >> 4) & 1;
       uint8_t psh = (flags >> 3) & 1;
       uint8_t rst = (flags >> 2) & 1;
       uint8_t syn = (flags >> 1) & 1;
       uint8_t fin = flags & 1;

       print_protocol_name("TCP");
       print_uint_field("Source Port", tcp.source_port);
       print_uint_field("Destination Port", tcp.destination_port);
       print_hex_field("Sequence Number", tcp.sequence_number, 8);
       print_hex_field("Acknowledgment Number", tcp.acknowledgment_number, 8);
       print_uint_bytes_field("Data Offset", data_offset * 4);
       print_bits_field("Reserved", reserved, RESERVED_BITS);

       printf("Flags\n");

       print_sub_uint_field("NS", ns);
       print_sub_uint_field("CWR", cwr);
       print_sub_uint_field("ECE", ece);
       print_sub_uint_field("URG", urg);
       print_sub_uint_field("ACK", ack);
       print_sub_uint_field("PSH", psh);
       print_sub_uint_field("RST", rst);
       print_sub_uint_field("SYN", syn);
       print_sub_uint_field("FIN", fin);

       print_hex_field("Window Size", tcp.window_size, 4);
       print_hex_field("Checksum", tcp.checksum, 4);
       print_hex_field("Urgent Pointer", tcp.urgent_pointer, 4);

       if (data_offset > 5)
       {
              int options_length = (data_offset - 5) * 4;

              char options_string[PRINT_LABEL_WIDTH];

              snprintf(options_string,
                       sizeof(options_string),
                       "Options (%d bytes)",
                       options_length);

              printf("%-*s: ",
                     PRINT_LABEL_WIDTH,
                     options_string);

              for (int i = 0; i < options_length; i++)
              {
                     printf("%02X ", tcp.options[i]);
              }
              printf("\n");
       }
       else
       {
              printf("%-*s: None\n",
                     PRINT_LABEL_WIDTH,
                     "Options");
       }
}