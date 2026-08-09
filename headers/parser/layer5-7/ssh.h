#ifndef SSH_H
#define SSH_H

#include <arpa/inet.h>

#include "../../common/types/packet.h"

int parse_ssh(Packet *packet, size_t *offset);

#endif