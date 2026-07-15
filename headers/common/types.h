#ifndef TYPES_H
#define TYPES_H

#include "define.h"

typedef struct
{
    unsigned char destination_mac[MAC_ADDRESS_SIZE];
    unsigned char source_mac[MAC_ADDRESS_SIZE];
    unsigned short ether_type;
} Ethernet;

typedef struct
{
    int packet_number;
    unsigned char data[MAX_PACKET_SIZE];
    size_t length;
    Ethernet ethernet;
} Packet;

#endif