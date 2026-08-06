#ifndef LAYER_2_PRINTER_H
#define LAYER_2_PRINTER_H

#include <stdio.h>

#include "../common/define.h"
#include "../common/utils.h"
#include "../common/types/layer2.h"
#include "../common/types/packet.h"

void print_ethernet(Ethernet ethernet, uint16_t *next_protocol);
void print_vlan(Vlan vlan, uint16_t *next_protocol);
void print_arp(Arp arp, uint16_t *next_protocol);
void print_layer2(Packet packet, uint16_t *next_protocol);

#endif