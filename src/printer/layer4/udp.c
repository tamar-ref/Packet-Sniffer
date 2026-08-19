#include "../../../headers/printer/layer4/udp.h"

void print_udp(Udp udp)
{
    printf("\n%-*s: UDP\n",
           PRINT_LABEL_WIDTH,
           "Protocol");

    printf("%-*s: %u\n",
           PRINT_LABEL_WIDTH,
           "Source Port",
           udp.source_port);

    printf("%-*s: %u\n",
           PRINT_LABEL_WIDTH,
           "Destination Port",
           udp.destination_port);

    printf("%-*s: %u\n",
           PRINT_LABEL_WIDTH,
           "Length",
           udp.length);

    printf("%-*s: 0x%04x\n",
           PRINT_LABEL_WIDTH,
           "Checksum",
           udp.checksum);
}