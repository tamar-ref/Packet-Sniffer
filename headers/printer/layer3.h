#ifndef LAYER_3_PRINTER_H
#define LAYER_3_PRINTER_H

#include <stdio.h>

#include "../common/utils.h"
#include "../common/types/packet.h"
#include "../common/types/layer3.h"

void print_ipv4(IPv4 ipv4);
void print_ipv6(IPv6 ipv6);
void print_icmp(Icmp icmp);
void print_layer3(Packet packet);

#endif