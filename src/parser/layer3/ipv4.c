#include "../../../headers/parser/layer3/ipv4.h"

int parse_ipv4(Packet *packet, size_t *offset, uint16_t *next_protocol)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    packet->has_ipv4 = 1;
    
    memcpy(&packet->ipv4,
           packet->payload + *offset,
           sizeof(packet->ipv4));

    packet->ipv4.total_length = ntohs(packet->ipv4.total_length);
    packet->ipv4.identification = ntohs(packet->ipv4.identification);
    packet->ipv4.flags_fragment_offset = ntohs(packet->ipv4.flags_fragment_offset);
    packet->ipv4.header_checksum = ntohs(packet->ipv4.header_checksum);

    *offset += sizeof(packet->ipv4);
    *next_protocol = packet->ipv4.protocol;

    return 0;
}