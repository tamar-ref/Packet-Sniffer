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
        if (*next_protocol == ICMP_PROTOCOL)
        {
            if (parse_icmp(packet, offset) != 0)
            {
                printf("ICMP Error\n");
                return -1;
            }
        }
    }
    else if (*next_protocol == IPV6_ETHERTYPE)
    {
        if (parse_ipv6(packet, offset, next_protocol) != 0)
        {
            printf("IPv6 Error\n");
            return -1;
        }
        if (*next_protocol == ICMPV6_PROTOCOL)
        {
            if (parse_icmpv6(packet, offset) != 0)
            {
                printf("ICMPv6 Error\n");
                return -1;
            }
        }
    }
    else
    {
        printf("Unknown Layer 3 Protocol: 0x%04X\n", *next_protocol);
        return -1;
    }

    return 0;
}

int parse_layer4(Packet *packet, size_t *offset, uint16_t *next_protocol)
{
    if (*next_protocol == TCP_PROTOCOL)
    {
        if (parse_tcp(packet, offset) != 0)
        {
            printf("TCP Error\n");
            return -1;
        }
    }
    else if (*next_protocol == UDP_PROTOCOL)
    {
        if (parse_udp(packet, offset) != 0)
        {
            printf("UDP Error\n");
            return -1;
        }
    }
    else
    {
        printf("Unknown Layer 4 Protocol: 0x%04X\n", *next_protocol);
        return -1;
    }

    return 0;
}

int parse_layer5_7(Packet *packet, size_t *offset)
{
    int known_protocol = 0;

    if (packet->has_tcp && (packet->tcp.destination_port == HTTP_PORT || packet->tcp.source_port == HTTP_PORT))
    {
        if (parse_http(packet, offset) != 0)
        {
            printf("HTTP Error\n");
            return -1;
        }
        known_protocol = 1;
    }
    if (packet->has_tcp && (packet->tcp.destination_port == HTTPS_PORT || packet->tcp.source_port == HTTPS_PORT))
    {
        if (parse_https(packet, offset) != 0)
        {
            printf("HTTPS Error\n");
            return -1;
        }
        known_protocol = 1;
    }
    if ((packet->has_tcp && (packet->tcp.destination_port == DNS_PORT || packet->tcp.source_port == DNS_PORT)) ||
        (packet->has_udp && (packet->udp.destination_port == DNS_PORT || packet->udp.source_port == DNS_PORT)))
    {
        if (parse_dns(packet, offset) != 0)
        {
            printf("DNS Error\n");
            return -1;
        }
        known_protocol = 1;
    }

    if (!known_protocol)
    {
        printf("Unknown Layer 5-7 Protocol\n");
        return -1;
    }

    return 0;
}

void parse_packet(Packet *packet, size_t *offset)
{
    uint16_t next_protocol;

    packet->has_vlan = 0;
    packet->has_arp = 0;
    if (parse_layer2(packet, offset, &next_protocol) != 0)
    {
        printf("Layer 2 Error\n");
        return;
    }

    if (packet->has_arp)
    {
        return;
    }

    packet->has_ipv4 = 0;
    packet->has_ipv6 = 0;
    packet->has_icmp = 0;
    packet->has_icmpv6 = 0;
    if (parse_layer3(packet, offset, &next_protocol) != 0)
    {
        printf("Layer 3 Error\n");
        return;
    }

    if (packet->has_icmp || packet->has_icmpv6)
    {
        return;
    }

    packet->has_tcp = 0;
    packet->has_udp = 0;
    if (parse_layer4(packet, offset, &next_protocol) != 0)
    {
        printf("Layer 4 Error\n");
        return;
    }

    packet->has_http = 0;
    packet->has_tls = 0;
    packet->has_dns = 0;
    if (parse_layer5_7(packet, offset) != 0)
    {
        printf("Layer 5-7 Error\n");
        return;
    }
}