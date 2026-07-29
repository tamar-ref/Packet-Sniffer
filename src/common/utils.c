#include "../../headers/common/utils.h"

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

void print_ip(unsigned char ip[IP_ADDRESS_SIZE])
{
    printf(
        "%d.%d.%d.%d",
        ip[0],
        ip[1],
        ip[2],
        ip[3]);
}