#ifndef PRINTER_H
#define PRINTER_H

#include <stdio.h>

#include "../common/types/packet.h"
#include "layer2.h"
#include "payload.h"

void print_packet(Packet packet);

#endif