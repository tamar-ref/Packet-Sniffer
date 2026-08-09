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
        if (parse_tcp(packet, offset, next_protocol) != 0)
        {
            printf("TCP Error\n");
            return -1;
        }
    }
    else if (*next_protocol == UDP_PROTOCOL)
    {
        if (parse_udp(packet, offset, next_protocol) != 0)
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

int parse_layer5_7(Packet *packet, size_t *offset, uint16_t *next_protocol)
{
    switch (*next_protocol)
    {

    case HTTP_PORT:
        if (parse_http(packet, offset) != 0)
        {
            printf("HTTP Error\n");
            return -1;
        }
        return 0;
        break;

    case HTTPS_PORT:
        if (parse_https(packet, offset) != 0)
        {
            printf("HTTPS Error\n");
            return -1;
        }
        return 0;
        break;

    case DNS_PORT:
        if (parse_dns(packet, offset) != 0)
        {
            printf("DNS Error\n");
            return -1;
        }
        return 0;
        break;

    case SERVER_DHCP_PORT:
        if (parse_server_dhcp(packet, offset) != 0)
        {
            printf("DHCP Error\n");
            return -1;
        }
        return 0;
        break;

    case CLIENT_DHCP_PORT:
        if (parse_client_dhcp(packet, offset) != 0)
        {
            printf("DHCP Error\n");
            return -1;
        }
        return 0;
        break;

    case CONTROL_FTP_PORT:
        if (parse_control_ftp(packet, offset) != 0)
        {
            printf("FTP Error\n");
            return -1;
        }
        return 0;
        break;

    case ACTIVE_FTP_PORT:
        if (parse_active_ftp(packet, offset) != 0)
        {
            printf("FTP Error\n");
            return -1;
        }
        return 0;
        break;

    case SSH_PORT:
        if (parse_ssh(packet, offset) != 0)
        {
            printf("SSH Error\n");
            return -1;
        }
        return 0;
        break;

    case NTP_PORT:
        if (parse_ntp(packet, offset) != 0)
        {
            printf("NTP Error\n");
            return -1;
        }
        return 0;
        break;

    case TELNET_PORT:
        if (parse_telnet(packet, offset) != 0)
        {
            printf("Telnet Error\n");
            return -1;
        }
        return 0;
        break;

    default:
        printf("Unknown Layer 5-7 port: 0x%04X\n", *next_protocol);
        return -1;
        break;
    }
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

    if (parse_layer5_7(packet, offset, &next_protocol) != 0)
    {
        printf("Layer 5-7 Error\n");
        return;
    }
}