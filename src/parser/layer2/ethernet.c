#include "../../../headers/parser/layer2/ethernet.h"

int parse_ethernet(
    const unsigned char *buffer,
    size_t length,
    Ethernet *ethernet)
{
    if (length < ETHERNET_HEADER_SIZE)
    {
        return -1;
    }

    memcpy(
        ethernet->destination_mac,
        buffer,
        MAC_ADDRESS_SIZE);

    memcpy(
        ethernet->source_mac,
        buffer + MAC_ADDRESS_SIZE,
        MAC_ADDRESS_SIZE);

    memcpy(
        &ethernet->ether_type,
        buffer + (MAC_ADDRESS_SIZE) * 2,
        ETHER_TYPE_SIZE);

    ethernet->ether_type =
        ntohs(ethernet->ether_type);

    return 0;
}