#ifndef ICMPV6_PARSER_H
#define ICMPV6_PARSER_H

#include <string.h>
#include <arpa/inet.h>

#include "../../common/types/packet.h"

int parse_icmpv6(Packet *packet, size_t *offset);

#endif