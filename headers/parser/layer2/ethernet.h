#ifndef ETHERNET_H
#define ETHERNET_H

#include "../../common/types.h"

int parse_ethernet(const unsigned char *buffer,
                    size_t length,
                    Ethernet *ethernet);

#endif