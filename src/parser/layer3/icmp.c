#include "../../../headers/parser/layer3/icmp.h"

int parse_icmp(Packet *packet, size_t *offset)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    packet->has_icmp = 1;

    memcpy(&packet->icmp,
           packet->payload + *offset,
           sizeof(Icmp));

    packet->icmp.checksum = ntohs(packet->icmp.checksum);
    packet->icmp.rest_of_header = ntohl(packet->icmp.rest_of_header);

    *offset += sizeof(Icmp);

    return 0;
}