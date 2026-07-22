#ifndef PACKET_TYPE_H
#define PACKET_TYPE_H

#include "../define.h"
#include "layer2.h"
#include "layer3.h"

typedef struct
{
    int packet_number;
    unsigned char payload[MAX_PACKET_SIZE];
    size_t length;
    Ethernet ethernet;
    int has_vlan;
    Vlan vlan;
} Packet;

#endif