#ifndef ICMP_H
#define ICMP_H

#include <string.h>
#include <arpa/inet.h>

#include "../../common/types/packet.h"

int parse_icmp(Packet *packet, size_t *offset);

#endif