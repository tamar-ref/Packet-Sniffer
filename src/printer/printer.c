#include "../../headers/printer/printer.h"

void print_layer2(Packet packet)
{
    printf("\nLayer 2\n");
    printf("-------------------------\n");

    print_ethernet(packet.ethernet);

    if (packet.has_vlan)
    {
        print_vlan(packet.vlan);
    }

    if (packet.has_arp)
    {
        print_arp(packet.arp);
    }
}

void print_layer3(Packet packet)
{
    printf("\nLayer 3\n");
    printf("-------------------------\n");

    if (packet.has_ipv4)
    {
        print_ipv4(packet.ipv4);
        if (packet.has_icmp)
        {
            print_icmp(packet.icmp);
        }
    }
    else if (packet.has_ipv6)
    {
        print_ipv6(packet.ipv6);
        if (packet.has_icmpv6)
        {
            print_icmpv6(packet.icmpv6);
        }
    }
    else
    {
        printf("Unknown Layer 3 Protocol\n");
    }
}

void print_layer4(Packet packet)
{
    printf("\nLayer 4\n");
    printf("-------------------------\n");

    if (packet.has_tcp)
    {
        print_tcp(packet.tcp);
    }
    else if (packet.has_udp)
    {
        print_udp(packet.udp);
    }
    else
    {
        printf("Unknown Layer 4 Protocol\n");
    }
}

void print_layer5_7(Packet packet)
{
    int known_protocol = 0;

    printf("\nLayer 5-7\n");
    printf("-------------------------\n");

    if (packet.has_http)
    {
        known_protocol = 1;
        print_http(packet.http);
    }
    if (packet.has_tls)
    {
        known_protocol = 1;
        print_https(packet.tls);
    }
    if (packet.has_dns)
    {
        known_protocol = 1;
        print_dns(packet.dns);
    }
    if (packet.has_dhcp)
    {
        known_protocol = 1;
        print_dhcp(packet.dhcp);
    }
    if (packet.has_ftp)
    {
        known_protocol = 1;
        print_ftp(packet.ftp);
    }
    if (packet.has_ssh)
    {
        known_protocol = 1;
        print_ssh(packet.ssh);
    }
    if (packet.has_ntp)
    {
        known_protocol = 1;
        print_ntp(packet.ntp);
    }
    if (packet.has_telnet)
    {
        known_protocol = 1;
        print_telnet(packet.telnet);
    }

    if (!known_protocol)
    {
        printf("Unknown Layer 5-7 Protocol\n");
    }
}

void print_packet(Packet packet)
{
    printf("\n\n");
    printf("====================================================\n");

    printf("Packet #%d\n", packet.packet_number);

    printf("Size: %zu bytes\n", packet.length);

    print_layer2(packet);

    if (!packet.has_arp)
    {
        print_layer3(packet);

        if (!packet.has_icmp && !packet.has_icmpv6)
        {
            print_layer4(packet);
            print_layer5_7(packet);
        }
    }

    print_payload(packet.payload, packet.length);

    printf("====================================================\n");
}