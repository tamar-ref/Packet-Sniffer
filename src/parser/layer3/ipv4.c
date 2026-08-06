#include "../../../headers/parser/layer3/ipv4.h"

int parse_ipv4(Packet *packet, size_t *offset, uint16_t *next_protocol)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    packet->has_ipv4 = 1;

    memcpy(&packet->ipv4.version_ihl,
           packet->payload + *offset,
           sizeof(packet->ipv4.version_ihl));
    *offset += sizeof(packet->ipv4.version_ihl);

    memcpy(&packet->ipv4.dscp,
           packet->payload + *offset,
           sizeof(packet->ipv4.dscp));
    *offset += sizeof(packet->ipv4.dscp);

    memcpy(&packet->ipv4.total_length,
           packet->payload + *offset,
           sizeof(packet->ipv4.total_length));
    packet->ipv4.total_length = ntohs(packet->ipv4.total_length);
    *offset += sizeof(packet->ipv4.total_length);

    memcpy(&packet->ipv4.identification,
           packet->payload + *offset,
           sizeof(packet->ipv4.identification));
    packet->ipv4.identification = ntohs(packet->ipv4.identification);
    *offset += sizeof(packet->ipv4.identification);

    memcpy(&packet->ipv4.flags_fragment_offset,
           packet->payload + *offset,
           sizeof(packet->ipv4.flags_fragment_offset));
    packet->ipv4.flags_fragment_offset = ntohs(packet->ipv4.flags_fragment_offset);
    *offset += sizeof(packet->ipv4.flags_fragment_offset);

    memcpy(&packet->ipv4.ttl,
           packet->payload + *offset,
           sizeof(packet->ipv4.ttl));
    *offset += sizeof(packet->ipv4.ttl);

    memcpy(&packet->ipv4.protocol,
           packet->payload + *offset,
           sizeof(packet->ipv4.protocol));
    *offset += sizeof(packet->ipv4.protocol);

    memcpy(&packet->ipv4.header_checksum,
           packet->payload + *offset,
           sizeof(packet->ipv4.header_checksum));
    packet->ipv4.header_checksum = ntohs(packet->ipv4.header_checksum);
    *offset += sizeof(packet->ipv4.header_checksum);

    memcpy(&packet->ipv4.source_ip,
           packet->payload + *offset,
           sizeof(packet->ipv4.source_ip));
    *offset += sizeof(packet->ipv4.source_ip);

    memcpy(&packet->ipv4.destination_ip,
           packet->payload + *offset,
           sizeof(packet->ipv4.destination_ip));
    *offset += sizeof(packet->ipv4.destination_ip);

    uint8_t ihl = packet->ipv4.version_ihl & 0x0F;
    if (ihl > 5)
    {
        memcpy(&packet->ipv4.options,
               packet->payload + *offset,
               (ihl - 5) * 4);
        *offset += (ihl - 5) * 4;
    }

    *next_protocol = packet->ipv4.protocol;

    return 0;
}