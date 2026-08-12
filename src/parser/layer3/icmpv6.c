#include "../../../headers/parser/layer3/icmpv6.h"

int parse_icmpv6(Packet *packet, size_t *offset)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    packet->has_icmpv6 = 1;

    memcpy(&packet->icmpv6,
           packet->payload + *offset,
           sizeof(packet->icmpv6));

    packet->icmpv6.checksum = ntohs(packet->icmpv6.checksum);
    packet->icmpv6.message_body = ntohl(packet->icmpv6.message_body);

    *offset += sizeof(packet->icmpv6);

    return 0;
}