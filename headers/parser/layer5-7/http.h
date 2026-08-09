#ifndef HTTP_H
#define HTTP_H

#include <arpa/inet.h>

#include "../../common/types/packet.h"

int parse_http(Packet *packet, size_t *offset);

#endif