#include "../../../headers/printer/layer5-7/dhcp.h"

void print_dhcp_option(DhcpOption option, int index)
{
       printf("Option %d\n", index);

       print_sub_uint_field("Code", option.code);
       print_sub_uint_field("Length", option.length);
       
       printf("%-*s%-*s: ",
              SUB_LABEL_WIDTH,
              "",
              PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH,
              "Data");

       for (uint16_t i = 0; i < option.length; i++)
       {
              printf("%02X ", option.data[i]);

              if (i < option.length - 1)
              {
                     printf(" ");
              }
       }
       printf("\n");
}

void print_dhcp(Dhcp dhcp)
{
       print_protocol_name("DHCP");
       print_hex_field("Operation", dhcp.op, 2);
       print_hex_field("Hardware Type", dhcp.htype, 2);
       print_uint_field("Hardware Length", dhcp.hlen);
       print_uint_field("Hops", dhcp.hops);
       print_hex_field("Transaction ID", dhcp.xid, 8);
       print_uint_field("Seconds", dhcp.secs);
       print_hex_field("Flags", dhcp.flags, 4);
       print_ip_field("Client IP Address", dhcp.ciaddr);
       print_ip_field("Your IP Address", dhcp.yiaddr);
       print_ip_field("Server IP Address", dhcp.siaddr);
       print_ip_field("Gateway IP Address", dhcp.giaddr);
       print_ip_field("Client Hardware Address", dhcp.chaddr);
       print_string_field("Server Name", dhcp.sname[0] != '\0' ? dhcp.sname : "None");
       print_string_field("Boot File", dhcp.file[0] != '\0' ? dhcp.file : "None");
       print_hex_field("Magic Cookie", dhcp.magic_cookie, 8);
       print_uint_field("Option Count", dhcp.option_count);

       for (int i = 0; i < dhcp.option_count; i++)
       {
              print_dhcp_option(dhcp.options[i], i + 1);
       }
}
