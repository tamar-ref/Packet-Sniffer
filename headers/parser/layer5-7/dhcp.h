#ifndef DHCP_H
#define DHCP_H

#include <arpa/inet.h>
#include <string.h>

#include "../../common/types/packet.h"

int parse_dhcp(Packet *packet, size_t *offset);

#endif