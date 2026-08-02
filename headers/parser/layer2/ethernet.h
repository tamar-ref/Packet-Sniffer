#ifndef ETHERNET_H
#define ETHERNET_H

#include <string.h>
#include <arpa/inet.h>

#include "../../common/types/packet.h"
#include "../../common/define.h"
#include "vlan.h"
#include "arp.h"
#include "../layer3/ipv4.h"

int parse_ethernet(Packet *packet, size_t *offset);

#endif