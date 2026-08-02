#ifndef IPV4
#define IPV4

#include <stddef.h>
#include <string.h>
#include <arpa/inet.h>

#include "../../common/types/packet.h"

int parse_ipv4(Packet *packet, size_t *offset);

#endif