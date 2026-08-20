#include "../../../headers/printer/layer3/ipv6.h"

void print_ipv6(IPv6 ipv6)
{
       uint32_t version = ipv6.version_traffic_class_flow_label >> 28;
       uint32_t traffic_class = (ipv6.version_traffic_class_flow_label >> 20) & 0xFF;
       uint32_t flow_label = ipv6.version_traffic_class_flow_label & 0xFFFFF;

       print_protocol_name("IPv6");
       print_uint_field("Version", version);
       print_hex_field("Traffic Class", traffic_class, 2);
       print_hex_field("Flow Label", flow_label, 5);
       print_hex_field("Payload Length", ipv6.payload_length, 4);
       print_hex_field("Next Header", ipv6.next_header, 2);
       print_hex_field("Hop Limit", ipv6.hop_limit, 2);
       print_address_field("Source IP Address", ipv6.source_address);
       print_address_field("Destination IP Address", ipv6.destination_address);
}