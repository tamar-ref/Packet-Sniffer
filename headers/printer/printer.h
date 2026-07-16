#ifndef PRINTER_H
#define PRINTER_H

#include <stdio.h>

#include "../common/types.h"
#include "ethernet.h"
#include "payload.h"
#include "ipv4.h"

void print_packet(Packet packet);

#endif