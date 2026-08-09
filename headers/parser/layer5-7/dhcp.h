#ifndef DHCP_H
#define DHCP_H

#include <arpa/inet.h>

#include "../../common/types/packet.h"

int parse_server_dhcp(Packet *packet, size_t *offset);
int parse_client_dhcp(Packet *packet, size_t *offset);

#endif