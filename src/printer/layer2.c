#include "../../headers/printer/layer2.h"

void print_ethernet(Ethernet ethernet)
{
    printf("\n%-*s: Ethernet II\n", PRINT_LABEL_WIDTH, "Protocol");

    printf("%-*s: ", PRINT_LABEL_WIDTH, "Destination MAC");
    print_mac(ethernet.destination_mac);
    printf("\n");

    printf("%-*s: ", PRINT_LABEL_WIDTH, "Source MAC");
    print_mac(ethernet.source_mac);
    printf("\n");

    printf("%-*s: 0x%04X\n", PRINT_LABEL_WIDTH, "EtherType", ethernet.ether_type);
}

void print_vlan(Vlan vlan)
{
    uint16_t pcp = (vlan.tci >> 13) & 0x07;
    uint16_t dei = (vlan.tci >> 12) & 0x01;
    uint16_t vid = vlan.tci & 0x0FFF;

    printf("\n%-*s: VLAN\n", PRINT_LABEL_WIDTH, "Protocol");

    printf("%-*s: 0x%04X\n", PRINT_LABEL_WIDTH, "TPID", vlan.tpid);

    printf("%-*s: %u\n", PRINT_LABEL_WIDTH, "Priority (PCP)", pcp);
    printf("%-*s: %u\n", PRINT_LABEL_WIDTH, "DEI", dei);
    printf("%-*s: %u\n", PRINT_LABEL_WIDTH, "VLAN ID", vid);

    printf("%-*s: 0x%04X\n", PRINT_LABEL_WIDTH, "EtherType", vlan.ether_type);
}

void print_arp(Arp arp)
{
    printf("\n%-*s: ARP\n", PRINT_LABEL_WIDTH, "Protocol");

    printf("%-*s: 0x%04X\n", PRINT_LABEL_WIDTH, "Hardware Type", arp.htype);
    printf("%-*s: 0x%04X\n", PRINT_LABEL_WIDTH, "Protocol Type", arp.ptype);
    printf("%-*s: 0x%02X\n", PRINT_LABEL_WIDTH, "Hardware Length", arp.hlen);
    printf("%-*s: 0x%02X\n", PRINT_LABEL_WIDTH, "Protocol Length", arp.plen);
    printf("%-*s: 0x%04X\n", PRINT_LABEL_WIDTH, "Opcode", arp.opcode);

    printf("%-*s: ", PRINT_LABEL_WIDTH, "Sender Hardware Address");
    print_mac(arp.sha);
    printf("\n");

    printf("%-*s: ", PRINT_LABEL_WIDTH, "Sender Protocol Address");
    print_ip(arp.spa);
    printf("\n");

    printf("%-*s: ", PRINT_LABEL_WIDTH, "Target Hardware Address");
    print_mac(arp.tha);
    printf("\n");

    printf("%-*s: ", PRINT_LABEL_WIDTH, "Target Protocol Address");
    print_ip(arp.tpa);
    printf("\n");
}

void print_layer2(Packet packet)
{
    printf("\nLayer 2\n");
    printf("-------------------------\n");

    print_ethernet(packet.ethernet);

    if (packet.has_vlan)
    {
        print_vlan(packet.vlan);
    }

    if (packet.has_arp)
    {
        print_arp(packet.arp);
    }
}