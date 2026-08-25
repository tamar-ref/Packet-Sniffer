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

       printf("\n");
       print_string_field("Protocol", "TCP", 0);
       print_uint_field("Source Port", tcp.source_port, 0);
       print_uint_field("Destination Port", tcp.destination_port, 0);
       print_hex_field("Sequence Number", tcp.sequence_number, 8, 0);
       print_hex_field("Acknowledgment Number", tcp.acknowledgment_number, 8, 0);
       print_uint_bytes_field("Data Offset", data_offset * 4, 0);
       print_bits_field("Reserved", reserved, RESERVED_BITS, 0);

       printf("Flags\n");

       print_uint_field("NS", ns, 1);
       print_uint_field("CWR", cwr, 1);
       print_uint_field("ECE", ece, 1);
       print_uint_field("URG", urg, 1);
       print_uint_field("ACK", ack, 1);
       print_uint_field("PSH", psh, 1);
       print_uint_field("RST", rst, 1);
       print_uint_field("SYN", syn, 1);
       print_uint_field("FIN", fin, 1);

       print_hex_field("Window Size", tcp.window_size, 4, 0);
       print_hex_field("Checksum", tcp.checksum, 4, 0);
       print_hex_field("Urgent Pointer", tcp.urgent_pointer, 4, 0);

       if (data_offset > 5)
       {
              int options_length = (data_offset - 5) * 4;

              char options_string[PRINT_LABEL_WIDTH];

              snprintf(options_string,
                       sizeof(options_string),
                       "Options (%d bytes)",
                       options_length);

              print_data(options_string, options_length, tcp.options, 0);
       }
       else
       {
              print_string_field("Options", "None", 0);
       }
}