#include "../../headers/printer/layer3.h"

void print_ipv4(IPv4 ipv4)
{
       printf("\n%-*s: IPv4\n", PRINT_LABEL_WIDTH, "Protocol");

       uint8_t version = ipv4.version_ihl >> 4;
       uint8_t ihl = ipv4.version_ihl & 0x0F;

       printf("%-*s: %u\n", PRINT_LABEL_WIDTH, "Version", version);
       printf("%-*s: %u bytes\n", PRINT_LABEL_WIDTH, "IHL", ihl * 4);
       printf("%-*s: 0x%04X\n", PRINT_LABEL_WIDTH, "Total Length", ipv4.total_length);
       printf("%-*s: 0x%04X\n", PRINT_LABEL_WIDTH, "Identification", ipv4.identification);

       uint16_t flags = (ipv4.flags_fragment_offset >> 13) & 0x07;
       uint16_t fragment_offset = ipv4.flags_fragment_offset & 0x1FFF;

       uint8_t reserved = (flags >> 2) & 1;
       uint8_t df = (flags >> 1) & 1;
       uint8_t mf = flags & 1;

       printf("Flags\n");
       printf("%-*s%-*s: %d\n", SUB_LABEL_WIDTH, "", PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH, "Reserved", reserved);
       printf("%-*s%-*s: %d\n", SUB_LABEL_WIDTH, "", PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH, "DF", df);
       printf("%-*s%-*s: %d\n", SUB_LABEL_WIDTH, "", PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH, "MF", mf);

       printf("%-*s: %u\n", PRINT_LABEL_WIDTH, "Fragment Offset", fragment_offset * 8);
       printf("%-*s: 0x%02x\n", PRINT_LABEL_WIDTH, "TTL", ipv4.ttl);
       printf("%-*s: 0x%02x\n", PRINT_LABEL_WIDTH, "Protocol", ipv4.protocol);
       printf("%-*s: 0x%02x\n", PRINT_LABEL_WIDTH, "Header Checksum", ipv4.header_checksum);

       printf("%-*s: ", PRINT_LABEL_WIDTH, "Source IP Address");
       print_ip(ipv4.source_ip);
       printf("\n");

       printf("%-*s: ", PRINT_LABEL_WIDTH, "Destination IP Address");
       print_ip(ipv4.destination_ip);
       printf("\n");

       if (ihl > 5)
       {
              int options_length = (ihl - 5) * 4;

              char options_string[PRINT_LABEL_WIDTH];
              snprintf(options_string,
                       sizeof(options_string),
                       "Options (%d bytes)",
                       options_length);
              printf("%-*s: ", PRINT_LABEL_WIDTH, options_string);

              for (int i = 0; i < options_length; i++)
              {
                     printf("%02X ", ipv4.options[i]);
              }
              printf("\n");
       }
       else
       {
              printf("%-*s: None\n", PRINT_LABEL_WIDTH, "Options");
       }
}

void print_ipv6(IPv6 ipv6)
{
       printf("\n%-*s: IPv6\n", PRINT_LABEL_WIDTH, "Protocol");

       uint32_t version = ipv6.version_traffic_class_flow_label >> 28;
       uint32_t traffic_class = (ipv6.version_traffic_class_flow_label >> 20) & 0xFF;
       uint32_t flow_label = ipv6.version_traffic_class_flow_label & 0xFFFFF;

       printf("%-*s: %u\n", PRINT_LABEL_WIDTH, "Version", version);
       printf("%-*s: 0x%02x\n", PRINT_LABEL_WIDTH, "Traffic Class", traffic_class);
       printf("%-*s: 0x%05x\n", PRINT_LABEL_WIDTH, "Flow Label", flow_label);

       printf("%-*s: 0x%04x\n", PRINT_LABEL_WIDTH, "Payload Length", ipv6.payload_length);
       printf("%-*s: 0x%02x\n", PRINT_LABEL_WIDTH, "Next Header", ipv6.next_header);
       printf("%-*s: 0x%02x\n", PRINT_LABEL_WIDTH, "Hop Limit", ipv6.hop_limit);

       printf("%-*s: ", PRINT_LABEL_WIDTH, "Source IP Address");
       print_address(ipv6.source_address);
       printf("\n");

       printf("%-*s: ", PRINT_LABEL_WIDTH, "Destination IP Address");
       print_address(ipv6.destination_address);
       printf("\n");
}

void print_icmp(Icmp icmp)
{
       printf("\n%-*s: ICMP\n", PRINT_LABEL_WIDTH, "Protocol");

       printf("%-*s: 0x%02x\n", PRINT_LABEL_WIDTH, "Type", icmp.type);
       printf("%-*s: 0x%02x\n", PRINT_LABEL_WIDTH, "Code", icmp.code);
       printf("%-*s: 0x%04x\n", PRINT_LABEL_WIDTH, "Checksum", icmp.checksum);
       printf("%-*s: 0x%08x\n", PRINT_LABEL_WIDTH, "Rest Of Header", icmp.rest_of_header);
}

void print_icmpv6(Icmpv6 icmpv6)
{
       printf("\n%-*s: ICMPv6\n", PRINT_LABEL_WIDTH, "Protocol");

       printf("%-*s: 0x%02x\n", PRINT_LABEL_WIDTH, "Type", icmpv6.type);
       printf("%-*s: 0x%02x\n", PRINT_LABEL_WIDTH, "Code", icmpv6.code);
       printf("%-*s: 0x%04x\n", PRINT_LABEL_WIDTH, "Checksum", icmpv6.checksum);
       printf("%-*s: 0x%08x\n", PRINT_LABEL_WIDTH, "Message Body", icmpv6.message_body);
}

void print_layer3(Packet packet)
{
       printf("\nLayer 3\n");
       printf("-------------------------\n");

       if (packet.has_ipv4)
       {
              print_ipv4(packet.ipv4);
              if (packet.has_icmp)
              {
                     print_icmp(packet.icmp);
              }
       }
       else if (packet.has_ipv6)
       {
              print_ipv6(packet.ipv6);
              if (packet.has_icmpv6)
              {
                     print_icmpv6(packet.icmpv6);
              }
       }
}