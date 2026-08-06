#include "../../headers/printer/printer.h"

void print_packet(Packet packet)
{
    printf("\n\n");
    printf("====================================================\n");

    printf("Packet #%d\n", packet.packet_number);

    printf("Size: %zu bytes\n", packet.length);

    uint16_t next_protocol;
    print_layer2(packet, &next_protocol);
    print_layer3(packet, &next_protocol);

    print_payload(packet.payload, packet.length);

    printf("====================================================\n");
}