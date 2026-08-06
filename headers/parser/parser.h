#ifndef PARSER_H
#define PARSER_H

#include <arpa/inet.h>

#include "../common/types/packet.h"
#include "../common/define.h"
#include "./layer2/ethernet.h"
#include "./layer2/arp.h"
#include "./layer2/vlan.h"
#include "./layer3/ipv4.h"
#include "./layer3/ipv6.h"

int parse_layer2(Packet *packet, size_t *offset, uint16_t *next_protocol);
int parse_layer3(Packet *packet, size_t *offset, uint16_t *next_protocol);
void parse_packet(Packet *packet, size_t *offset);

#endif