#ifndef LAYER_4_PRINTER_H
#define LAYER_4_PRINTER_H

#include <stdio.h>

#include "../common/utils.h"
#include "../common/define.h"
#include "../common/types/packet.h"
#include "../common/types/layer4.h"

void print_tcp(Tcp tcp);
void print_layer4(Packet packet);

#endif