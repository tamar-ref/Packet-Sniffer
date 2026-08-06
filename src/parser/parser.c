#include "../../headers/parser/parser.h"

void parse_packet(Packet *packet, size_t *offset)
{
    uint16_t next_protocol;
    // layer 2
    parse_ethernet(packet, offset, &next_protocol);

    if (next_protocol == TPID)
    {
        if (parse_vlan(packet, offset, &next_protocol) != 0)
        {
            printf("VLAN Error\n");
            return;
        }
    }

    if (next_protocol == ARP_ETHERTYPE)
    {
        if (parse_arp(packet, offset, &next_protocol) != 0)
        {
            printf("ARP Error\n");
            return;
        }
    }

    // layer 3
    if (next_protocol == IPV4_ETHERTYPE)
    {
        if (parse_ipv4(packet, offset, &next_protocol) != 0)
        {
            printf("IPv4 Error\n");
            return;
        }
    }
    else if (next_protocol == IPV6_ETHERTYPE)
    {
        if (parse_ipv6(packet, offset, &next_protocol) != 0)
        {
            printf("IPv6 Error\n");
            return;
        }
    }
}