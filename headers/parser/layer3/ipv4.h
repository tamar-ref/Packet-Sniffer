#ifndef IPV4
#define IPV4

#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include <arpa/inet.h>

#include "../../common/types.h"
#include "../../common/define.h"

int parse_ipv4(
    const unsigned char *buffer,
    size_t length,
    IPv4 *ipv4);

#endif