#include "../../headers/printer/layer2.h"

void print_ethernet(Ethernet ethernet, uint16_t *next_protocol)
{
    printf("Protocol                : Ethernet II\n");

    printf("Destination MAC         : ");
    print_mac(ethernet.destination_mac);
    printf("\n");

    printf("Source MAC              : ");
    print_mac(ethernet.source_mac);
    printf("\n");

    printf("EtherType               : 0x%04X\n", ethernet.ether_type);

    *next_protocol = ethernet.ether_type;
}

void print_vlan(Vlan vlan, uint16_t *next_protocol)
{
    uint16_t pcp = (vlan.tci >> 13) & 0x07;
    uint16_t dei = (vlan.tci >> 12) & 0x01;
    uint16_t vid = vlan.tci & 0x0FFF;

    printf("\nProtocol                : VLAN\n");

    printf("TPID                    : 0x%04X\n", vlan.tpid);

    printf("Priority (PCP)          : %u\n", pcp);
    printf("DEI                     : %u\n", dei);
    printf("VLAN ID                 : %u\n", vid);

    printf("EtherType               : 0x%04X\n", vlan.ether_type);

    *next_protocol = vlan.ether_type;
}

void print_arp(Arp arp, uint16_t *next_protocol)
{
    printf("\nProtocol                : ARP\n");

    printf("Hardware Type           : 0x%04X\n", arp.htype);
    printf("Protocol Type           : 0x%04X\n", arp.ptype);
    printf("Hardware Length         : 0x%02X\n", arp.hlen);
    printf("Protocol Length         : 0x%02X\n", arp.plen);
    printf("Opcode                  : 0x%04X\n", arp.opcode);

    printf("Sender Hardware Address : ");
    print_mac(arp.sha);
    printf("\n");

    printf("Sender Protocol Address : ");
    print_ip(arp.spa);
    printf("\n");

    printf("Sender Hardware Address : ");
    print_mac(arp.tha);
    printf("\n");

    printf("Target Protocol Address : ");
    print_ip(arp.tpa);
    printf("\n");

    *next_protocol = IPV4_ETHERTYPE;
}

void print_layer2(Packet packet, uint16_t *next_protocol)
{
    printf("\nLayer 2\n");
    printf("-------------------------\n");

    print_ethernet(packet.ethernet, next_protocol);

    if (*next_protocol == TPID)
    {
        print_vlan(packet.vlan, next_protocol);
    }

    if (*next_protocol == ARP_ETHERTYPE)
    {
        print_arp(packet.arp, next_protocol);
    }
}