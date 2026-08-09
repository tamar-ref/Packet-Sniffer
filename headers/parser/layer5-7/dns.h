#ifndef DNS_H
#define DNS_H

#include <arpa/inet.h>

#include "../../common/types/packet.h"

int parse_dns(Packet *packet, size_t *offset);

#endif