#ifndef HTTPS_H
#define HTTPS_H

#include <arpa/inet.h>

#include "../../common/types/packet.h"

int parse_https(Packet *packet, size_t *offset);

#endif