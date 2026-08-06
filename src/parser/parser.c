#include "../../headers/parser/parser.h"

int parse_layer2(Packet *packet, size_t *offset, uint16_t *next_protocol)
{
    parse_ethernet(packet, offset, next_protocol);

    if (*next_protocol == TPID)
    {
        if (parse_vlan(packet, offset, next_protocol) != 0)
        {
            printf("VLAN Error\n");
            return -1;
        }
    }

    if (*next_protocol == ARP_ETHERTYPE)
    {
        if (parse_arp(packet, offset, next_protocol) != 0)
        {
            printf("ARP Error\n");
            return -1;
        }
    }

    return 0;
}

int parse_layer3(Packet *packet, size_t *offset, uint16_t *next_protocol)
{
    if (*next_protocol == IPV4_ETHERTYPE)
    {
        if (parse_ipv4(packet, offset, next_protocol) != 0)
        {
            printf("IPv4 Error\n");
            return -1;
        }
    }
    else if (*next_protocol == IPV6_ETHERTYPE)
    {
        if (parse_ipv6(packet, offset, next_protocol) != 0)
        {
            printf("IPv6 Error\n");
            return -1;
        }
    }
    else
    {
        printf("Unknown Layer 3 Protocol: 0x%04X\n", *next_protocol);
        return -1;
    }

    return 0;
}

void parse_packet(Packet *packet, size_t *offset)
{
    uint16_t next_protocol;

    if (parse_layer2(packet, offset, &next_protocol) != 0)
    {
        printf("Layer 2 Error\n");
        return;
    }

    if (parse_layer3(packet, offset, &next_protocol) != 0)
    {
        printf("Layer 3 Error\n");
        return;
    }
}