#ifndef PACKET_TYPE_H
#define PACKET_TYPE_H

#include "../define.h"
#include "layer2.h"
#include "layer3.h"
#include "layer4.h"

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
    int has_tcp;
    Tcp tcp;
} Packet;

#endif