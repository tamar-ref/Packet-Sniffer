#include "../../headers/printer/payload.h"

void print_hex(const unsigned char *data, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        printf("%02X ", data[i]);
        if ((i + 1) % 16 == 0)
        {
            printf("\n");
        }
    }
    if (length % 16 != 0)
    {
        printf("\n");
    }
}

void print_ascii(const unsigned char *data, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        if (data[i] >= 32 && data[i] <= 126)
        {
            printf("%c", data[i]);
        }
        else
        {
            printf(".");
        }
    }
    printf("\n");
}

void print_payload(const unsigned char *data, size_t length)
{
    printf("\nPayload (HEX)\n");
    printf("----------------\n");

    print_hex(data, length);

    printf("\nPayload (ASCII)\n");
    printf("----------------\n");

    print_ascii(data, length);
}