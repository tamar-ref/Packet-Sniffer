#ifndef SSH_PARSER_H
#define SSH_PARSER_H

#include <arpa/inet.h>
#include <string.h>

#include "../../common/types/packet.h"

int is_ssh_identification(Packet *packet, size_t *offset);
int is_ssh_packet(Packet *packet, size_t *offset);
int parse_ssh_identification(Packet *packet, size_t *offset);
int parse_ssh_packet(Packet *packet, size_t *offset);
int parse_ssh(Packet *packet, size_t *offset);

#endif