#ifndef HTTP_H
#define HTTP_H

#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>

#include "../../common/types/packet.h"

int is_http_request(Packet *packet, size_t *offset);
int is_http_response(Packet *packet, size_t *offset);
int parse_http_headers(Packet *packet, size_t *offset);
int parse_http_request(Packet *packet, size_t *offset);
int parse_http_response(Packet *packet, size_t *offset);
int parse_http(Packet *packet, size_t *offset);

#endif