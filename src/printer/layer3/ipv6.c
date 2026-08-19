#include "../../../headers/printer/layer3/ipv6.h"

void print_ipv6(IPv6 ipv6)
{
    printf("\n%-*s: IPv6\n",
           PRINT_LABEL_WIDTH,
           "Protocol");

    uint32_t version = ipv6.version_traffic_class_flow_label >> 28;
    uint32_t traffic_class = (ipv6.version_traffic_class_flow_label >> 20) & 0xFF;
    uint32_t flow_label = ipv6.version_traffic_class_flow_label & 0xFFFFF;

    printf("%-*s: %u\n",
           PRINT_LABEL_WIDTH,
           "Version",
           version);
    printf("%-*s: 0x%02x\n",
           PRINT_LABEL_WIDTH,
           "Traffic Class",
           traffic_class);

    printf("%-*s: 0x%05x\n",
           PRINT_LABEL_WIDTH,
           "Flow Label",
           flow_label);

    printf("%-*s: 0x%04x\n",
           PRINT_LABEL_WIDTH,
           "Payload Length",
           ipv6.payload_length);

    printf("%-*s: 0x%02x\n",
           PRINT_LABEL_WIDTH,
           "Next Header",
           ipv6.next_header);

    printf("%-*s: 0x%02x\n",
           PRINT_LABEL_WIDTH,
           "Hop Limit",
           ipv6.hop_limit);

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Source IP Address");
    print_address(ipv6.source_address);
    printf("\n");

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Destination IP Address");
    print_address(ipv6.destination_address);
    printf("\n");
}