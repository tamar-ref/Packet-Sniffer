#include "../../../headers/printer/layer3/icmpv6.h"

void print_icmpv6(Icmpv6 icmpv6)
{
       print_protocol_name("ICMPv6");
       print_hex_field("Type", icmpv6.type, 2);
       print_hex_field("Code", icmpv6.code, 2);
       print_hex_field("Checksum", icmpv6.checksum, 4);
       print_hex_field("Message Body", icmpv6.message_body, 8);
}