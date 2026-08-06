#include "../../../headers/parser/layer3/ipv6.h"

int parse_ipv6(Packet *packet, size_t *offset)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    memcpy(&packet->ipv6,
           packet->payload + *offset,
           sizeof(packet->ipv6));

    packet->ipv6.version_traffic_class_flow_label = ntohl(packet->ipv6.version_traffic_class_flow_label);
    packet->ipv6.payload_length = ntohs(packet->ipv6.payload_length);

    *offset += sizeof(packet->ipv6);

    return 0;
}