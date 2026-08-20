#include "../../../headers/printer/layer3/ipv4.h"

void print_ipv4(IPv4 ipv4)
{
       uint8_t version = ipv4.version_ihl >> 4;
       uint8_t ihl = ipv4.version_ihl & 0x0F;

       uint16_t flags = (ipv4.flags_fragment_offset >> 13) & 0x07;
       uint16_t fragment_offset = ipv4.flags_fragment_offset & 0x1FFF;

       uint8_t reserved = (flags >> 2) & 1;
       uint8_t df = (flags >> 1) & 1;
       uint8_t mf = flags & 1;

       print_protocol_name("IPv4");
       print_uint_field("Version", version);
       print_uint_bytes_field("IHL", ihl * 4);
       print_hex_field("Total Length", ipv4.total_length, 4);
       print_hex_field("Identification", ipv4.identification, 4);

       printf("Flags\n");

       print_sub_uint_field("Reserved", reserved);
       print_sub_uint_field("DF", df);
       print_sub_uint_field("MF", mf);
       print_uint_field("Fragment Offset", fragment_offset * 8);
       print_hex_field("TTL", ipv4.ttl, 2);
       print_hex_field("Protocol", ipv4.protocol, 2);
       print_hex_field("Header Checksum", ipv4.header_checksum, 2);
       print_ip_field("Source IP Address", ipv4.source_ip);
       print_ip_field("Destination IP Address", ipv4.source_ip);

       if (ihl > 5)
       {
              int options_length = (ihl - 5) * 4;

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
                     printf("%02X ", ipv4.options[i]);
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