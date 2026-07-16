#include "../../headers/printer/printer.h"

void print_packet(Packet packet)
{
    printf("\n\n");
    printf("====================================================\n");

    printf("Packet #%d\n", packet.packet_number);

    printf("Size: %zu bytes\n", packet.length);

    print_ethernet(packet.ethernet);

    // צריך לבדוק שיש IPv4
    print_ipv4(packet.ipv4);

    /*
        print_vlan(...);
        print_arp(...);
        print_ipv6(...);
        print_tcp(...);
        print_udp(...);
        print_http(...);
        print_dns(...);
    */

    print_payload(packet.data, packet.length);

    printf("====================================================\n");
}