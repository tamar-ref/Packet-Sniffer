#ifndef IPV4_H
#define IPV4_H

#include <string.h>
#include <arpa/inet.h>

#include "../../common/types/packet.h"

int parse_ipv4(Packet *packet, size_t *offset, uint16_t *next_protocol);

#endif