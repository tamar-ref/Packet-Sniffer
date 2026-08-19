#include "../../../headers/printer/layer2/ethernet.h"

void print_ethernet(Ethernet ethernet)
{
    printf("\n%-*s: Ethernet II\n",
           PRINT_LABEL_WIDTH,
           "Protocol");

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Destination MAC");
    print_mac(ethernet.destination_mac);
    printf("\n");

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Source MAC");
    print_mac(ethernet.source_mac);
    printf("\n");

    printf("%-*s: 0x%04X\n",
           PRINT_LABEL_WIDTH,
           "EtherType",
           ethernet.ether_type);
}