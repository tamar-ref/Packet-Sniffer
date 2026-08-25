#include "../../../headers/printer/layer2/vlan.h"

void print_vlan(Vlan vlan)
{
       uint16_t pcp = (vlan.tci >> 13) & 0x07;
       uint16_t dei = (vlan.tci >> 12) & 0x01;
       uint16_t vid = vlan.tci & 0x0FFF;

       printf("\n");
       print_string_field("Protocol", "VLAN", 0);
       print_hex_field("TPID", vlan.tpid, 4, 0);
       print_uint_field("Priority (PCP)", pcp, 0);
       print_uint_field("DEI", dei, 0);
       print_uint_field("VLAN ID", vid, 0);
       print_hex_field("EtherType", vlan.ether_type, 4, 0);
}