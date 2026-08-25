#ifndef PACKET_TYPE_H
#define PACKET_TYPE_H

#include "../define.h"
#include "layer2.h"
#include "layer3.h"
#include "layer4.h"
#include "layer5-7.h"

typedef struct
{
    int packet_number;
    unsigned char payload[MAX_PACKET_SIZE];
    size_t length;

    Ethernet ethernet;
    int has_vlan;
    Vlan vlan;
    int has_arp;
    Arp arp;

    int has_ipv4;
    IPv4 ipv4;
    int has_ipv6;
    IPv6 ipv6;
    int has_icmp;
    Icmp icmp;
    int has_icmpv6;
    Icmpv6 icmpv6;

    int has_tcp;
    Tcp tcp;
    int has_udp;
    Udp udp;

    int has_http;
    Http http;
    int has_tls;
    Tls tls;
    int has_dns;
    Dns dns;
    int has_dhcp;
    Dhcp dhcp;
    int has_ftp;
    Ftp ftp;
    int has_ssh;
    Ssh ssh;
    int has_ntp;
    Ntp ntp;
    int has_telnet;
    Telnet telnet;
} Packet;

#endif