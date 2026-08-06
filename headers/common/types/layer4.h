#ifndef LAYER4_TYPE_H
#define LAYER4_TYPE_H

#include <stdint.h>

#include "../define.h"

#pragma pack(push, 1)

typedef struct
{
    uint16_t source_port;
    uint16_t destination_port;
    uint32_t sequence_number;
    uint32_t acknowledgment_number;
    uint16_t data_offset_reserved_flags;
    // data_offset : 4
    // reserved : 3
    // flags : 9
    uint16_t window_size;
    uint16_t checksum;
    uint16_t urgent_pointer;
    uint8_t options[MAX_OPTIONS_SIZE];
} Tcp;

typedef struct
{
    uint16_t source_port;
    uint16_t destination_port;
    uint16_t length;
    uint16_t checksum;
} Udp;

#pragma pack(pop)

#endif