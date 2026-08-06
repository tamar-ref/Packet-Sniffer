#include "../../../headers/parser/layer2/ethernet.h"

int parse_ethernet(Packet *packet, size_t *offset, uint16_t *next_protocol)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    memcpy(&packet->ethernet,
           packet->payload + *offset,
           sizeof(Ethernet));
    packet->ethernet.ether_type = ntohs(packet->ethernet.ether_type);
    
    *offset += sizeof(Ethernet);
    *next_protocol = packet->ethernet.ether_type;

    return 0;
}