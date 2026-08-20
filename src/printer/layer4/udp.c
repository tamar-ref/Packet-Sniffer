#include "../../../headers/printer/layer4/udp.h"

void print_udp(Udp udp)
{
       print_protocol_name("UDP");
       print_uint_field("Source Port", udp.source_port);
       print_uint_field("Destination Port", udp.destination_port);
       print_uint_field("Length", udp.length);
       print_hex_field("Checksum", udp.checksum, 4);
}