#include "../../headers/printer/ethernet.h"

void print_ethernet(Ethernet ethernet)
{
    printf("\nLayer 2\n");
    printf("-----------------\n");

    printf("Protocol : Ethernet II\n");

    printf("Destination MAC : ");
    print_mac(ethernet.destination_mac);

    printf("\n");

    printf("Source MAC      : ");
    print_mac(ethernet.source_mac);

    printf("\n");

    printf("EtherType       : 0x%04X\n",
           ethernet.ether_type);
}