#include "../../../headers/parser/layer4/udp.h"

int parse_udp(Packet *packet, size_t *offset)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    packet->has_udp = 1;

    memcpy(&packet->udp,
           packet->payload + *offset,
           sizeof(Udp));

    packet->udp.source_port = ntohs(packet->udp.source_port);
    packet->udp.destination_port = ntohs(packet->udp.destination_port);
    packet->udp.length = ntohs(packet->udp.length);
    packet->udp.checksum = ntohs(packet->udp.checksum);

    *offset += sizeof(Udp);

    return 0;
}