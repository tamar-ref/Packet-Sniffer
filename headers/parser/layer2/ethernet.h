#ifndef ETHERNET_H
#define ETHERNET_H

#include <string.h>
#include <arpa/inet.h>

#include "../../common/types/packet.h"
#include "../../common/define.h"
#include "vlan.h"

int parse_ethernet(Packet *packet, size_t *offset);

#endif