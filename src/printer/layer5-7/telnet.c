#include "../../../headers/printer/layer5-7/telnet.h"

char *telnet_command_name(uint8_t command)
{
    switch (command)
    {
    case TELNET_SE:
        return "SE";
    case TELNET_NOP:
        return "NOP";
    case TELNET_DM:
        return "DM";
    case TELNET_BRK:
        return "BRK";
    case TELNET_IP:
        return "IP";
    case TELNET_AO:
        return "AO";
    case TELNET_AYT:
        return "AYT";
    case TELNET_EC:
        return "EC";
    case TELNET_EL:
        return "EL";
    case TELNET_GA:
        return "GA";
    case TELNET_SB:
        return "SB";
    case TELNET_WILL:
        return "WILL";
    case TELNET_WONT:
        return "WONT";
    case TELNET_DO:
        return "DO";
    case TELNET_DONT:
        return "DONT";
    default:
        return "Unknown";
    }
}
void print_telnet(Telnet telnet)
{
    printf("\n");
    print_string_field("Protocol", "Telnet", 0);
    print_uint_field("Data Length", telnet.data_length, 0);
    print_data("Data", telnet.data_length, telnet.data, 0);
    print_uint_field("Command Count", telnet.command_count, 0);
    for (int i = 0; i < telnet.command_count; i++)
    {
        printf("Command %d\n", i + 1);
        print_string_field("Command", telnet_command_name(telnet.commands[i].command), 1);
        if (telnet.commands[i].has_option)
        {
            print_hex_field("Option", telnet.commands[i].option, 2, 1);
        }
    }
}