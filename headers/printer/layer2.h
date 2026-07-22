#ifndef LAYER_2_PRINTER_H
#define LAYER_2_PRINTER_H

#include <stdio.h>

#include "../common/utils.h"
#include "../common/types/layer2.h"
#include "../common/types/packet.h"

void print_ethernet(Ethernet ethernet);
void print_vlan(Vlan vlan);
void print_layer2(Packet packet);

#endif