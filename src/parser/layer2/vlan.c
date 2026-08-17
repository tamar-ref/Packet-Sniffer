#include "../../../headers/parser/layer2/vlan.h"

int parse_vlan(Packet *packet, size_t *offset, uint16_t *next_protocol)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    packet->has_vlan = 1;
    *offset -= sizeof(packet->ethernet.ether_type);

    memcpy(&packet->vlan,
           packet->payload + *offset,
           sizeof(packet->vlan));

    packet->vlan.tpid = ntohs(packet->vlan.tpid);
    packet->vlan.tci = ntohs(packet->vlan.tci);
    packet->vlan.ether_type = ntohs(packet->vlan.ether_type);
    
    *offset += sizeof(Vlan);
    *next_protocol = packet->vlan.ether_type;

    return 0;
}
