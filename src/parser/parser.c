#include "../../headers/parser/parser.h"

int parse_layer2(Packet *packet, size_t *offset, uint16_t *next_protocol)
{
    if (parse_ethernet(packet, offset, next_protocol) != 0)
    {
        printf("Ethernet Error\n");
        return -1;
    }

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
    if (packet->has_tcp)
    {
        if (packet->tcp.destination_port == HTTP_PORT || packet->tcp.source_port == HTTP_PORT)
        {
            if (parse_http(packet, offset) != 0)
            {
                printf("HTTP Error\n");
                return -1;
            }
        }

        if (packet->tcp.destination_port == HTTPS_PORT || packet->tcp.source_port == HTTPS_PORT)
        {
            if (parse_https(packet, offset) != 0)
            {
                printf("HTTPS Error\n");
                return -1;
            }
        }

        if (packet->tcp.destination_port == DNS_PORT || packet->tcp.source_port == DNS_PORT)
        {
            if (parse_dns(packet, offset) != 0)
            {
                printf("DNS Error\n");
                return -1;
            }
        }

        if (packet->tcp.destination_port == CONTROL_FTP_PORT ||
            packet->tcp.destination_port == ACTIVE_FTP_PORT ||
            packet->tcp.source_port == CONTROL_FTP_PORT ||
            packet->tcp.source_port == ACTIVE_FTP_PORT)
        {
            if (parse_ftp(packet, offset) != 0)
            {
                printf("FTP Error\n");
                return -1;
            }
        }

        if (packet->tcp.destination_port == SSH_PORT || packet->tcp.source_port == SSH_PORT)
        {
            if (parse_ssh(packet, offset) != 0)
            {
                printf("SSH Error\n");
                return -1;
            }
        }

        if (packet->tcp.destination_port == TELNET_PORT || packet->tcp.source_port == TELNET_PORT)
        {
            if (parse_telnet(packet, offset) != 0)
            {
                printf("Telnet Error\n");
                return -1;
            }
        }
    }
    else if (packet->has_udp)
    {
        if (packet->has_udp && (packet->udp.destination_port == DNS_PORT || packet->udp.source_port == DNS_PORT))
        {
            if (parse_dns(packet, offset) != 0)
            {
                printf("DNS Error\n");
                return -1;
            }
        }

        if (packet->udp.destination_port == SERVER_DHCP_PORT ||
            packet->udp.destination_port == CLIENT_DHCP_PORT ||
            packet->udp.source_port == SERVER_DHCP_PORT ||
            packet->udp.source_port == CLIENT_DHCP_PORT)
        {
            if (parse_dhcp(packet, offset) != 0)
            {
                printf("DHCP Error\n");
                return -1;
            }
        }

        if (packet->udp.destination_port == NTP_PORT || packet->udp.source_port == NTP_PORT)
        {
            if (parse_ntp(packet, offset) != 0)
            {
                printf("NTP Error\n");
                return -1;
            }
        }
    }

    return 0;
}

void parse_packet(Packet *packet, size_t *offset)
{
    uint16_t next_protocol;

    packet->has_vlan = 0;
    packet->has_arp = 0;
    packet->has_ipv4 = 0;
    packet->has_ipv6 = 0;
    packet->has_icmp = 0;
    packet->has_icmpv6 = 0;
    packet->has_tcp = 0;
    packet->has_udp = 0;
    packet->has_http = 0;
    packet->has_tls = 0;
    packet->has_dns = 0;
    packet->has_dhcp = 0;
    packet->has_ftp = 0;
    packet->has_ssh = 0;
    packet->has_ntp = 0;
    packet->has_telnet = 0;

    if (parse_layer2(packet, offset, &next_protocol) != 0)
    {
        printf("Layer 2 Error\n");
        return;
    }
    if (packet->has_arp)
    {
        return;
    }

    if (parse_layer3(packet, offset, &next_protocol) != 0)
    {
        printf("Layer 3 Error\n");
        return;
    }
    if (packet->has_icmp || packet->has_icmpv6)
    {
        return;
    }

    if (parse_layer4(packet, offset, &next_protocol) != 0)
    {
        printf("Layer 4 Error\n");
        return;
    }

    if (parse_layer5_7(packet, offset) != 0)
    {
        printf("Layer 5-7 Error\n");
        return;
    }
}