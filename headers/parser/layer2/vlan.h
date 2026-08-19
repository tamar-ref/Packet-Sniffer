#ifndef VLAN_PARSER_H
#define VLAN_PARSER_H

#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>

#include "../../common/types/packet.h"

int parse_vlan(Packet *packet, size_t *offset, uint16_t *next_protocol);

#endif