#include "../../../headers/parser/layer2/ethernet.h"

int parse_ethernet(Packet *packet, size_t *offset)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    packet->has_vlan = 0;

    memcpy(&packet->ethernet,
           packet->payload + *offset,
           sizeof(Ethernet));
    packet->ethernet.ether_type = ntohs(packet->ethernet.ether_type);

    *offset += sizeof(Ethernet);
    uint16_t ether_type = packet->ethernet.ether_type;

    if (packet->ethernet.ether_type == TPID)
    {
        if (parse_vlan(packet, offset) != 0)
        {
            return -1;
        }
        if (packet->has_vlan)
        {
            ether_type = packet->vlan.ether_type;
        }
    }

    if (ether_type == ARP_ETHERTYPE)
    {
        if (parse_arp(packet, offset) != 0)
        {
            return -1;
        }
        if (parse_ipv4(packet, offset) != 0)
        {
            return -1;
        }
    }

    return 0;
}