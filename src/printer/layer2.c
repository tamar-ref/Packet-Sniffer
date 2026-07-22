#include "../../headers/printer/layer2.h"

void print_ethernet(Ethernet ethernet)
{
    printf("Protocol        : Ethernet II\n");

    printf("Destination MAC : ");
    print_mac(ethernet.destination_mac);
    printf("\n");

    printf("Source MAC      : ");
    print_mac(ethernet.source_mac);
    printf("\n");

    printf("EtherType       : 0x%04X\n", ethernet.ether_type);
}

void print_vlan(Vlan vlan)
{
    uint16_t pcp = (vlan.tci >> 13) & 0x07;
    uint16_t dei = (vlan.tci >> 12) & 0x01;
    uint16_t vid = vlan.tci & 0x0FFF;

    printf("\nProtocol        : VLAN\n");

    printf("TPID            : 0x%04X\n", vlan.tpid);

    printf("Priority (PCP)  : %u\n", pcp);
    printf("DEI             : %u\n", dei);
    printf("VLAN ID (VID)   : %u\n", vid);

    printf("EtherType       : 0x%04X\n", vlan.ether_type);
}

void print_layer2(Packet packet)
{
    printf("\nLayer 2\n");
    printf("-----------------\n");

    print_ethernet(packet.ethernet);

    if (packet.has_vlan)
    {
        print_vlan(packet.vlan);
    }
}