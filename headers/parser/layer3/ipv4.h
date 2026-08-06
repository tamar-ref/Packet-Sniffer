#ifndef IPV4
#define IPV4

#include <string.h>
#include <arpa/inet.h>

#include "../../common/types/packet.h"

int parse_ipv4(Packet *packet, size_t *offset, uint16_t *next_protocol);

#endif