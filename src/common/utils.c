#include <stdio.h>

#include "../../headers/common/define.h"

void print_mac(unsigned char mac[MAC_ADDRESS_SIZE])
{
    printf(
        "%02X:%02X:%02X:%02X:%02X:%02X",
        mac[0],
        mac[1],
        mac[2],
        mac[3],
        mac[4],
        mac[5]);
}