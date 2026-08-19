#include "../../../headers/printer/layer2/arp.h"

void print_arp(Arp arp)
{
    printf("\n%-*s: ARP\n",
           PRINT_LABEL_WIDTH,
           "Protocol");

    printf("%-*s: 0x%04X\n",
           PRINT_LABEL_WIDTH,
           "Hardware Type",
           arp.htype);

    printf("%-*s: 0x%04X\n",
           PRINT_LABEL_WIDTH,
           "Protocol Type",
           arp.ptype);

    printf("%-*s: 0x%02X\n",
           PRINT_LABEL_WIDTH,
           "Hardware Length",
           arp.hlen);

    printf("%-*s: 0x%02X\n",
           PRINT_LABEL_WIDTH,
           "Protocol Length",
           arp.plen);

    printf("%-*s: 0x%04X\n",
           PRINT_LABEL_WIDTH,
           "Opcode",
           arp.opcode);

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Sender Hardware Address");
    print_mac(arp.sha);
    printf("\n");

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Sender Protocol Address");
    print_ip(arp.spa);
    printf("\n");

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Target Hardware Address");
    print_mac(arp.tha);
    printf("\n");

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Target Protocol Address");
    print_ip(arp.tpa);
    printf("\n");
}