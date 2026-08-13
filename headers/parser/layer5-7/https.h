#ifndef HTTPS_H
#define HTTPS_H

#include <arpa/inet.h>
#include <string.h>

#include "../../common/types/packet.h"
#include "../../common/types/layer5-7.h"

int is_tls(Packet *packet, size_t *offset);
int parse_https(Packet *packet, size_t *offset);

#endif