#ifndef LAYER4_TYPE_H
#define LAYER4_TYPE_H

#include <stdint.h>

#include "../define.h"

#pragma pack(push, 1)

typedef struct
{
    uint16_t source_port;
    uint16_t destination_port;
    uint32_t sequense_number;
    uint32_t acknowledgment_number;
    uint16_t data_offset : 4;
    uint16_t reserved : 3;
    uint16_t flags : 9;
    uint16_t window_size;
    uint16_t checksum;
    uint16_t urgent_pointer;
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