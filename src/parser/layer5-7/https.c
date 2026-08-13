#include "../../../headers/parser/layer5-7/https.h"

int is_tls(Packet *packet, size_t *offset)
{
    uint8_t content_type = packet->payload[*offset];

    if (content_type != 0x14 &&
        content_type != 0x15 &&
        content_type != 0x16 &&
        content_type != 0x17)
    {
        return 0;
    }

    return 1;
}

int parse_https(Packet *packet, size_t *offset)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    if (is_tls(packet, offset) == 0)
    {
        return -1;
    }

    memcpy(
        &packet->tls,
        packet->payload + *offset,
        sizeof(Tls) - sizeof(packet->tls.fragment));

    packet->tls.version = ntohs(packet->tls.version);
    packet->tls.length = ntohs(packet->tls.length);

    *offset += sizeof(Tls) - sizeof(packet->tls.fragment);

    if (packet->tls.length > 0)
    {
        memcpy(&packet->tls.fragment,
               packet->payload + *offset,
               packet->tls.length);
        *offset += packet->tls.length;
    }

    return 0;
}