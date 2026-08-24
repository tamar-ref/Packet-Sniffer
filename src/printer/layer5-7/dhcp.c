#include "../../../headers/printer/layer5-7/dhcp.h"

void print_dhcp_option(DhcpOption option, int index)
{
       printf("Option %d\n", index);

       print_uint_field("Code", option.code, 1);
       print_uint_field("Length", option.length, 1);
       print_data("Data", option.length, option.data, 1);
}

void print_dhcp(Dhcp dhcp)
{
       print_string_field("Protocol", "DHCP", 0);
       print_hex_field("Operation", dhcp.op, 2, 0);
       print_hex_field("Hardware Type", dhcp.htype, 2, 0);
       print_uint_field("Hardware Length", dhcp.hlen, 0);
       print_uint_field("Hops", dhcp.hops, 0);
       print_hex_field("Transaction ID", dhcp.xid, 8, 0);
       print_uint_field("Seconds", dhcp.secs, 0);
       print_hex_field("Flags", dhcp.flags, 4, 0);
       print_ip_field("Client IP Address", dhcp.ciaddr, 0);
       print_ip_field("Your IP Address", dhcp.yiaddr, 0);
       print_ip_field("Server IP Address", dhcp.siaddr, 0);
       print_ip_field("Gateway IP Address", dhcp.giaddr, 0);
       print_ip_field("Client Hardware Address", dhcp.chaddr, 0);
       print_string_field("Server Name", dhcp.sname[0] != '\0' ? dhcp.sname : "None", 0);
       print_string_field("Boot File", dhcp.file[0] != '\0' ? dhcp.file : "None", 0);
       print_hex_field("Magic Cookie", dhcp.magic_cookie, 8, 0);
       print_uint_field("Option Count", dhcp.option_count, 0);

       for (int i = 0; i < dhcp.option_count; i++)
       {
              print_dhcp_option(dhcp.options[i], i + 1);
       }
}
