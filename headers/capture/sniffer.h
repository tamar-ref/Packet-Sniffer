#ifndef CAPTURE_H
#define CAPTURE_H

#include <stdlib.h>
#include <linux/if_ether.h>
#include <unistd.h>

#include "../printer/printer.h"
#include "../common/types/packet.h"
#include "../parser/layer2/ethernet.h"
#include "../parser/layer3/ipv4.h"

void start_sniffer();

#endif