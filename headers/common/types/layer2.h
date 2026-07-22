#ifndef LAYER2_TYPE_H
#define LAYER2_TYPE_H

#include <stdint.h>

#include "../define.h"

#pragma pack(push, 1)

typedef struct
{
    uint16_t tpid;
    uint16_t tci;
    // pcp : 3;
    // dei : 1;
    // vid : 12;
    uint16_t ether_type;
} Vlan;

typedef struct
{
    uint16_t htype;
    uint16_t ptype;
    uint8_t hlen;
    uint8_t plen;
    uint16_t opcode;
    uint8_t sha[MAC_ADDRESS_SIZE];
    uint32_t spa;
    uint8_t tha[MAC_ADDRESS_SIZE];
    uint32_t tpa;
} Arp;

typedef struct
{
    uint8_t destination_mac[MAC_ADDRESS_SIZE];
    uint8_t source_mac[MAC_ADDRESS_SIZE];
    uint16_t ether_type;
} Ethernet;

#pragma pack(pop)

#endif