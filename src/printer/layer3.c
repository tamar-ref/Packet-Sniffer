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

void print_ipv6(IPv6 ipv6)
{
       printf("Protocol                : IPv6\n");

       uint32_t version = ipv6.version_traffic_class_flow_label >> 28;
       uint32_t traffic_class = (ipv6.version_traffic_class_flow_label >> 20) & 0xFF;
       uint32_t flow_label = ipv6.version_traffic_class_flow_label & 0xFFFFF;

       printf("Version                 : %u\n", version);
       printf("Traffic Class           : 0x%02X\n", traffic_class);
       printf("Flow Label              : 0x%05X\n", flow_label);

       printf("Payload Length          : 0x%04x\n", ipv6.payload_length);
       printf("Next Header             : 0x%02x\n", ipv6.next_header);
       printf("Hop Limit               : 0x%02x\n", ipv6.hop_limit);

       printf("Source IP Address       : ");
       print_address(ipv6.source_address);
       printf("\n");

       printf("Destination IP Address  : ");
       print_address(ipv6.destination_address);
       printf("\n");
}

void print_layer3(Packet packet)
{
       printf("\nLayer 3\n");
       printf("-------------------------\n");
       uint16_t ether_type = packet.has_vlan
                                 ? packet.vlan.ether_type
                                 : packet.ethernet.ether_type;
       if (ether_type == ARP_ETHERTYPE)
       {
              print_ipv4(packet.ipv4);
       }
       else if (ether_type == IPV6_ETHERTYPE)
       {
              print_ipv6(packet.ipv6);
       }
       else
       {
              printf("Unknown Layer 3 Protocol\n");
       }
}