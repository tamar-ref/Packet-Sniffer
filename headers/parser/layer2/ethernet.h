#ifndef ETHERNET_PARSER_H
#define ETHERNET_PARSER_H

#include <string.h>
#include <arpa/inet.h>

#include "../../common/types/packet.h"

int parse_ethernet(Packet *packet, size_t *offset, uint16_t *next_protocol);

#endif