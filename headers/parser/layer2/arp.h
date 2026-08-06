#ifndef ARP_H
#define ARP_H

#include <string.h>
#include <arpa/inet.h>

#include "../../common/types/packet.h"

int parse_arp(Packet *packet, size_t *offset, uint16_t *next_protocol);

#endif