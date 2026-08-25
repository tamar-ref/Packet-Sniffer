#include "../../../headers/printer/layer2/arp.h"

void print_arp(Arp arp)
{
       printf("\n");
       print_string_field("Protocol", "ARP", 0);
       print_hex_field("Hardware Type", arp.htype, 4, 0);
       print_hex_field("Protocol Type", arp.ptype, 4, 0);
       print_hex_field("Hardware Length", arp.hlen, 2, 0);
       print_hex_field("Protocol Length", arp.plen, 2, 0);
       print_hex_field("Opcode", arp.opcode, 4, 0);
       print_mac_field("Sender Hardware Address", arp.sha, 0);
       print_ip_field("Sender Protocol Address", arp.spa, 0);
       print_mac_field("Target Hardware Address", arp.tha, 0);
       print_ip_field("Target Protocol Address", arp.tpa, 0);
}