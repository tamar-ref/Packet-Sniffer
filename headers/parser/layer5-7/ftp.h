#ifndef FTP_H
#define FTP_H

#include <arpa/inet.h>

#include "../../common/types/packet.h"

int parse_control_ftp(Packet *packet, size_t *offset);
int parse_active_ftp(Packet *packet, size_t *offset);

#endif