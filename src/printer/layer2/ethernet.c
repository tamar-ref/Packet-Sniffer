#include "../../../headers/printer/layer2/ethernet.h"

void print_ethernet(Ethernet ethernet)
{
       print_string_field("Protocol","Ethernet II",0);
       print_mac_field("Destination MAC", ethernet.destination_mac,0);
       print_mac_field("Source MAC", ethernet.destination_mac,0);
       print_hex_field("EtherType", ethernet.ether_type, 4,0);
}