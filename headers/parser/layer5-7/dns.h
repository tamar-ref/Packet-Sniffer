#ifndef DNS_PARSER_H
#define DNS_PARSER_H

#include <arpa/inet.h>
#include <string.h>

#include "../../common/types/packet.h"

int parse_dns_name(
    Packet *packet,
    size_t *offset,
    size_t dns_start,
    char *name,
    size_t name_size);

int parse_dns_question(
    Packet *packet,
    size_t *offset,
    size_t dns_start,
    DnsQuestion *question);

int parse_dns_record(
    Packet *packet,
    size_t *offset,
    size_t dns_start,
    DnsRecord *record);

int parse_dns(Packet *packet, size_t *offset);

#endif