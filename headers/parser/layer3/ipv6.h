#ifndef IPV6_H
#define IPV6_H

#include <string.h>
#include <arpa/inet.h>

#include "../../common/types/packet.h"

int parse_ipv6(Packet *packet, size_t *offset, uint16_t *next_protocol);

#endif