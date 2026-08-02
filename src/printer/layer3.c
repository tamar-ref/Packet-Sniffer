#include "../../headers/printer/layer3.h"

void print_ipv4(IPv4 ipv4)
{
       printf("\nProtocol                : IPv4\n");

       uint8_t version = ipv4.version_ihl >> 4;
       uint8_t ihl = ipv4.version_ihl & 0x0F;

       uint16_t flags = (ipv4.flags_fragment_offset >> 13) & 0x07;
       uint16_t fragment_offset = ipv4.flags_fragment_offset & 0x1FFF;

       printf("Version                 : %u\n", version);
       printf("IHL                     : %u bytes\n", ihl * 4);
       printf("Total Length            : 0x%04x\n", ipv4.total_length);
       printf("Identification          : 0x%04X\n", ipv4.identification);

       printf("Flags                   : ");
       printf("Reserved %d\n", (flags >> 2) & 1);
       printf("                          DF       %d\n", (flags >> 1) & 1);
       printf("                          MF       %d\n", (flags >> 0) & 1);

       printf("Fragment Offset         : %u\n", fragment_offset * 8);

       printf("TTL                     : 0x%02x\n", ipv4.ttl);
       printf("Protocol                : 0x%02x\n", ipv4.protocol);
       printf("Header Checksum         : 0x%02x\n", ipv4.header_checksum);

       printf("Source IP Address       : ");
       print_ip(ipv4.source_ip);
       printf("\n");

       printf("Destination IP Address  : ");
       print_ip(ipv4.destination_ip);
       printf("\n");

       if (ihl > 5)
       {
              int options_length = (ihl - 5) * 4;
              printf("Options (%d bytes)       : ", options_length);
              for (int i = 0; i < options_length; i++)
              {
                     printf("%02X ", ipv4.options[i]);
              }
              printf("\n");
       }
       else
       {
              printf("Options                 : None\n");
       }
}

void print_layer3(Packet packet)
{
       printf("\nLayer 3\n");
       printf("-------------------------\n");
       print_ipv4(packet.ipv4);
}