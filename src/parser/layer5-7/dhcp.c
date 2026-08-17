#include "../../../headers/parser/layer5-7/dhcp.h"

int parse_dhcp(Packet *packet, size_t *offset)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    packet->has_dhcp = 1;
    size_t basic_dhcp_size = sizeof(Dhcp) - sizeof(packet->dhcp.options) - sizeof(packet->dhcp.option_count);

    memcpy(&packet->dhcp,
           packet->payload + *offset,
           basic_dhcp_size);

    packet->dhcp.xid = ntohl(packet->dhcp.xid);
    packet->dhcp.secs = ntohs(packet->dhcp.secs);
    packet->dhcp.flags = ntohs(packet->dhcp.flags);
    packet->dhcp.magic_cookie = ntohl(packet->dhcp.magic_cookie);

    *offset += basic_dhcp_size;

    packet->dhcp.option_count = 0;

    while (*offset < packet->length && packet->dhcp.option_count < MAX_DHCP_OPTIONS)
    {
        uint8_t code = packet->payload[*offset];

        if (code == 0)
        {
            (*offset)++;
            continue;
        }

        if (code == 255)
        {
            (*offset)++;
            break;
        }

        packet->dhcp.options[packet->dhcp.option_count].code = code;
        (*offset)++;

        packet->dhcp.options[packet->dhcp.option_count].length = packet->payload[*offset];
        (*offset)++;

        memcpy(
            packet->dhcp.options[packet->dhcp.option_count].data,
            packet->payload + *offset,
            packet->dhcp.options[packet->dhcp.option_count].length);

        *offset += packet->dhcp.options[packet->dhcp.option_count].length;

        packet->dhcp.option_count++;
    }

    return 0;
}