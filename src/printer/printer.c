#include "../../headers/printer/printer.h"

void print_packet(Packet packet)
{
    printf("\n\n");
    printf("====================================================\n");

    printf("Packet #%d\n", packet.packet_number);

    printf("Size: %zu bytes\n", packet.length);

    print_layer2(packet);

    if (!packet.has_arp)
    {
        print_layer3(packet);

        if (!packet.has_icmp && !packet.has_icmpv6)
        {
            print_layer4(packet);
            print_layer5_7(packet);
        }
    }

    print_payload(packet.payload, packet.length);

    printf("====================================================\n");
}