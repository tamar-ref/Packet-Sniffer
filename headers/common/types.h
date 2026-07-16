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
    unsigned char version;
    unsigned char header_length;
    unsigned char dscp;
    unsigned char ecn;
    unsigned short total_length;
    unsigned short identification;
    unsigned short flags;
    unsigned short fragment_offset;
    unsigned char ttl;
    unsigned char protocol;
    unsigned short header_checksum;
    unsigned int source_ip;
    unsigned int destination_ip;
} IPv4;

typedef struct
{
    int packet_number;
    unsigned char data[MAX_PACKET_SIZE];
    size_t length;
    Ethernet ethernet;
    IPv4 ipv4;
} Packet;

#endif