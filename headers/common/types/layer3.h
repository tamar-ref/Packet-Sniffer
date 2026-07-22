#ifndef LAYER3_TYPE_H
#define LAYER3_TYPE_H

#include <stdint.h>

#include "../define.h"

#pragma pack(push, 1)

typedef struct
{
    uint8_t version : 4;
    uint8_t ihl : 4;
    uint8_t dscp;
    uint16_t total_length;
    uint16_t identification;
    uint16_t flags : 3;
    uint16_t fragment_offset : 13;
    uint8_t ttl;
    uint8_t protocol;
    uint16_t header_checksum;
    uint32_t source_ip;
    uint32_t destination_ip;
} IPv4;

typedef struct
{
    uint32_t version : 4;
    uint32_t traffic_class : 8;
    uint32_t flow_label : 20;
    uint16_t payload_length;
    uint8_t next_header;
    uint8_t hop_limit;
    uint8_t source_address[16];
    uint8_t destination_address[16];
} IPv6;

#pragma pack(pop)

#endif