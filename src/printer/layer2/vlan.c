#include "../../../headers/printer/layer2/vlan.h"

void print_vlan(Vlan vlan)
{
       uint16_t pcp = (vlan.tci >> 13) & 0x07;
       uint16_t dei = (vlan.tci >> 12) & 0x01;
       uint16_t vid = vlan.tci & 0x0FFF;

       print_protocol_name("VLAN");
       print_hex_field("TPID", vlan.tpid, 4);
       print_uint_field("Priority (PCP)", pcp);
       print_uint_field("DEI", dei);
       print_uint_field("VLAN ID", vid);
       print_hex_field("EtherType", vlan.ether_type, 4);
}