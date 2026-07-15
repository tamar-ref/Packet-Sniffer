#include <stdio.h>

#include "../../headers/output/printer.h"

void print_hex(unsigned char *data, int length)
{

    for (int i = 0; i < length; i++)
    {
        printf("%02X ", data[i]);

        if ((i + 1) % 16 == 0)
        {
            printf("\n");
        }
    }

    printf("\n");
}

void print_ascii(unsigned char *data, int length)
{

    for (int i = 0; i < length; i++)
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

void print_packet(Packet packet)
{

    printf("\n\n\n");
    printf("====================================================\n");

    printf("Packet #%d\n", packet.packet_number);

    printf("Size: %d bytes\n", packet.length);

    printf("\nPayload (HEX)\n");
    printf("----------------\n");

    print_hex(packet.data, packet.length);

    printf("\nPayload (ASCII)\n");
    printf("----------------\n");

    print_ascii(packet.data, packet.length);

    printf("====================================================\n");
}