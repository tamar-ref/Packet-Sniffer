#ifndef NTP_H
#define NTP_H

#include <arpa/inet.h>

#include "../../common/types/packet.h"

int parse_ntp(Packet *packet, size_t *offset);

#endif