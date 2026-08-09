#ifndef UDP_H
#define UDP_H

#include <string.h>
#include <arpa/inet.h>

#include "../../common/types/packet.h"

int parse_udp(Packet *packet, size_t *offset, uint16_t *next_protocol);

#endif