#ifndef IPV6
#define IPV6

#include <string.h>
#include <arpa/inet.h>

#include "../../common/types/packet.h"

int parse_ipv6(Packet *packet, size_t *offset);

#endif