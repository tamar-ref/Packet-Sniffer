#ifndef NTP_PARSER_H
#define NTP_PARSER_H

#include <arpa/inet.h>
#include <endian.h>
#include <string.h>

#include "../../common/types/packet.h"

int is_ntp(Packet *packet, size_t *offset);
int parse_ntp(Packet *packet, size_t *offset);

#endif