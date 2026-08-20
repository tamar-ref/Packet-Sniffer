#include "../../../headers/printer/layer2/arp.h"

void print_arp(Arp arp)
{
       print_protocol_name("ARP");
       print_hex_field("Hardware Type", arp.htype, 4);
       print_hex_field("Protocol Type", arp.ptype, 4);
       print_hex_field("Hardware Length", arp.hlen, 2);
       print_hex_field("Protocol Length", arp.plen, 2);
       print_hex_field("Opcode", arp.opcode, 4);
       print_mac_field("Sender Hardware Address", arp.sha);
       print_ip_field("Sender Protocol Address", arp.spa);
       print_mac_field("Target Hardware Address", arp.tha);
       print_ip_field("Target Protocol Address", arp.tpa);
}