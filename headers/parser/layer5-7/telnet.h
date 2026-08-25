#ifndef TELNET_PARSER_H
#define TELNET_PARSER_H

#include <arpa/inet.h>
#include <string.h>

#include "../../common/types/packet.h"
#include "../../common/define.h"

int is_telnet(Packet *packet, size_t *offset);
int parse_telnet(Packet *packet, size_t *offset);

#endif