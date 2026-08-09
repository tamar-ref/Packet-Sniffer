#ifndef TELNET_H
#define TELNET_H

#include <arpa/inet.h>

#include "../../common/types/packet.h"

int parse_telnet(Packet *packet, size_t *offset);

#endif