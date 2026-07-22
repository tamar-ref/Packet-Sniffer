#include "../../headers/printer/printer.h"

void print_packet(Packet packet)
{
    printf("\n\n");
    printf("====================================================\n");

    printf("Packet #%d\n", packet.packet_number);

    printf("Size: %zu bytes\n", packet.length);

    print_layer2(packet);

    print_payload(packet.payload, packet.length);

    printf("====================================================\n");
}