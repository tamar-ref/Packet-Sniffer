#ifndef CAPTURE_H
#define CAPTURE_H

#include <linux/if_ether.h>

#include "../printer/printer.h"
#include "../common/types/packet.h"
#include "../parser/parser.h"

void start_sniffer();

#endif