#include "../../../headers/printer/layer3/icmp.h"

void print_icmp(Icmp icmp)
{
       print_protocol_name("ICMP");
       print_hex_field("Type", icmp.type, 2);
       print_hex_field("Code", icmp.code, 2);
       print_hex_field("Checksum", icmp.checksum, 4);
       print_hex_field("Rest Of Header", icmp.rest_of_header, 8);
}
