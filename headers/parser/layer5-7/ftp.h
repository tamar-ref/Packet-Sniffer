#ifndef FTP_H
#define FTP_H

#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

#include "../../common/types/packet.h"

int is_ftp_request(Packet *packet, size_t *offset);
int is_ftp_response(Packet *packet, size_t *offset);
int parse_ftp_request(Packet *packet, size_t *offset);
int parse_ftp_response(Packet *packet, size_t *offset);
int parse_ftp(Packet *packet, size_t *offset);

#endif