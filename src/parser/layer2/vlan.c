#include "../../../headers/parser/layer2/vlan.h"

int parse_vlan(Packet *packet, size_t *offset)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    packet->has_vlan = 1;
    packet->vlan.tpid = packet->ethernet.ether_type;

    memcpy(&packet->vlan.tci,
           packet->payload + *offset,
           sizeof(packet->vlan.tci));
    packet->vlan.tci = ntohs(packet->vlan.tci);
    *offset += sizeof(packet->vlan.tci);

    memcpy(&packet->vlan.ether_type,
           packet->payload + *offset,
           sizeof(packet->vlan.ether_type));
    packet->vlan.ether_type = ntohs(packet->vlan.ether_type);
    *offset += sizeof(packet->vlan.ether_type);

    return 0;
}
