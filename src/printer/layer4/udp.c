#include "../../../headers/printer/layer4/udp.h"

void print_udp(Udp udp)
{
       printf("\n");
       print_string_field("Protocol", "UDP", 0);
       print_uint_field("Source Port", udp.source_port, 0);
       print_uint_field("Destination Port", udp.destination_port, 0);
       print_uint_field("Length", udp.length, 0);
       print_hex_field("Checksum", udp.checksum, 4, 0);
}