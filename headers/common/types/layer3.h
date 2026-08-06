#ifndef LAYER3_TYPE_H
#define LAYER3_TYPE_H

#include <stdint.h>

#include "../define.h"

#pragma pack(push, 1)

typedef struct
{
    uint8_t version_ihl;
    // version : 4
    // ihl : 4
    uint8_t dscp;
    uint16_t total_length;
    uint16_t identification;
    uint16_t flags_fragment_offset;
    // flags : 3
    // fragment_offset : 13
    uint8_t ttl;
    uint8_t protocol;
    uint16_t header_checksum;
    uint8_t source_ip[IP_ADDRESS_SIZE];
    uint8_t destination_ip[IP_ADDRESS_SIZE];
    uint8_t options[MAX_OPTIONS_SIZE];
} IPv4;

typedef struct
{
    uint32_t version_traffic_class_flow_label;
    // version : 4
    // traffic_class : 8
    // flow_label : 20
    uint16_t payload_length;
    uint8_t next_header;
    uint8_t hop_limit;
    uint8_t source_address[ADDRESS_SIZE];
    uint8_t destination_address[ADDRESS_SIZE];
} IPv6;

#pragma pack(pop)

#endif