#ifndef ETHERNET_H
#define ETHERNET_H

#include <string.h>
#include <arpa/inet.h>

#include "../../common/types.h"
#include "../../common/define.h"

int parse_ethernet(const unsigned char *buffer,
                    size_t length,
                    Ethernet *ethernet);

#endif