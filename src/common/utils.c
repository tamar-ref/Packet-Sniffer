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

void print_address(uint8_t address[ADDRESS_SIZE])
{
    for (int i = 0; i < ADDRESS_SIZE; i += 2)
    {
        uint16_t part =
            ((uint16_t)address[i] << 8) |
            address[i + 1];

        printf("%04x", part);

        if (i < ADDRESS_SIZE - 2)
        {
            printf(":");
        }
    }
}

void print_bits(uint16_t value, int bits)
{
    printf("0b");
    for (int i = bits - 1; i >= 0; i--)
    {
        printf("%u", (value >> i) & 1);
    }
}