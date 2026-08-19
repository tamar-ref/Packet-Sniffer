#ifndef ICMP_PARSER_H
#define ICMP_PARSER_H

#include <string.h>
#include <arpa/inet.h>

#include "../../common/types/packet.h"

int parse_icmp(Packet *packet, size_t *offset);

#endif