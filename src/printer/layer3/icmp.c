#include "../../../headers/printer/layer3/icmp.h"

void print_icmp(Icmp icmp)
{
       printf("\n");
       print_string_field("Protocol", "ICMP", 0);
       print_hex_field("Type", icmp.type, 2, 0);
       print_hex_field("Code", icmp.code, 2, 0);
       print_hex_field("Checksum", icmp.checksum, 4, 0);
       print_hex_field("Rest Of Header", icmp.rest_of_header, 8, 0);
}
