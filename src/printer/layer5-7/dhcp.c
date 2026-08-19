#include "../../../headers/printer/layer5-7/dhcp.h"

void print_dhcp_option(DhcpOption option, int index)
{
    printf("Option %d\n",
           index);

    printf("%-*s%-*s: %u\n",
           SUB_LABEL_WIDTH,
           "",
           PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH,
           "Code",
           option.code);

    printf("%-*s%-*s: %u\n",
           SUB_LABEL_WIDTH,
           "",
           PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH,
           "Length",
           option.length);

    printf("%-*s%-*s: ",
           SUB_LABEL_WIDTH,
           "",
           PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH,
           "Data");

    for (uint16_t i = 0; i < option.length; i++)
    {
        printf("%02X ",
               option.data[i]);

        if (i < option.length - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void print_dhcp(Dhcp dhcp)
{
    printf("\n%-*s: DHCP\n",
           PRINT_LABEL_WIDTH,
           "Protocol");

    printf("%-*s: 0x%02X\n",
           PRINT_LABEL_WIDTH,
           "Operation",
           dhcp.op);

    printf("%-*s: 0x%02X\n",
           PRINT_LABEL_WIDTH,
           "Hardware Type",
           dhcp.htype);

    printf("%-*s: %u\n",
           PRINT_LABEL_WIDTH,
           "Hardware Length",
           dhcp.hlen);

    printf("%-*s: %u\n",
           PRINT_LABEL_WIDTH,
           "Hops",
           dhcp.hops);

    printf("%-*s: 0x%08X\n",
           PRINT_LABEL_WIDTH,
           "Transaction ID",
           dhcp.xid);

    printf("%-*s: %u\n",
           PRINT_LABEL_WIDTH,
           "Seconds",
           dhcp.secs);

    printf("%-*s: 0x%04X\n",
           PRINT_LABEL_WIDTH,
           "Flags",
           dhcp.flags);

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Client IP Address");
    print_ip(dhcp.ciaddr);
    printf("\n");

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Your IP Address");
    print_ip(dhcp.yiaddr);
    printf("\n");

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Server IP Address");
    print_ip(dhcp.siaddr);
    printf("\n");

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Gateway IP Address");
    print_ip(dhcp.giaddr);
    printf("\n");

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Client Hardware Address");
    print_mac(dhcp.chaddr);
    printf("\n");

    printf("%-*s: %s\n",
           PRINT_LABEL_WIDTH,
           "Server Name",
           dhcp.sname[0] != '\0' ? dhcp.sname : "None");

    printf("%-*s: %s\n",
           PRINT_LABEL_WIDTH,
           "Boot File",
           dhcp.file[0] != '\0' ? dhcp.file : "None");

    printf("%-*s: 0x%08X\n",
           PRINT_LABEL_WIDTH,
           "Magic Cookie",
           dhcp.magic_cookie);

    printf("%-*s: %d\n",
           PRINT_LABEL_WIDTH,
           "Option Count",
           dhcp.option_count);

    for (int i = 0; i < dhcp.option_count; i++)
    {
        print_dhcp_option(dhcp.options[i], i + 1);
    }
}
