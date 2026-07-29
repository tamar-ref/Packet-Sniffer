#include "../../../headers/parser/layer2/arp.h"

int parse_arp(Packet *packet, size_t *offset)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    packet->has_arp = 1;

    memcpy(&packet->arp,
           packet->payload + *offset,
           sizeof(packet->arp));

    packet->arp.htype = ntohs(packet->arp.htype);
    packet->arp.ptype = ntohs(packet->arp.ptype);
    packet->arp.opcode = ntohs(packet->arp.opcode);

    *offset += sizeof(packet->arp);

    return 0;
}