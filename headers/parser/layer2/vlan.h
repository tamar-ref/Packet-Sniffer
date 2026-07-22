#ifndef VLAN_H
#define VLAN_H

#include <string.h>
#include <stdio.h>

#include "../../common/types/packet.h"
#include <arpa/inet.h>

int parse_vlan(Packet *packet, size_t *offset);

#endif