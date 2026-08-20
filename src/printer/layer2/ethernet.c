#include "../../../headers/printer/layer2/ethernet.h"

void print_ethernet(Ethernet ethernet)
{
       print_protocol_name("Ethernet II");
       print_mac_field("Destination MAC", ethernet.destination_mac);
       print_mac_field("Source MAC", ethernet.destination_mac);
       print_hex_field("EtherType", ethernet.ether_type, 4);
}