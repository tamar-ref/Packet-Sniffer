#include "../../../headers/parser/layer5-7/ntp.h"

int is_ntp(Packet *packet, size_t *offset)
{
    if (*offset + sizeof(Ntp) > packet->length)
    {
        return 0;
    }

    uint8_t li_vn_mode = packet->payload[*offset];
    uint8_t version = (li_vn_mode >> 3) & 0x07;
    uint8_t mode = li_vn_mode & 0x07;

    if (version < 3 || version > 4)
    {
        return 0;
    }

    if (mode < 1 || mode > 5)
    {
        return 0;
    }

    return 1;
}

int parse_ntp(Packet *packet, size_t *offset)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    if (is_ntp(packet, offset))
    {
        packet->has_ntp = 1;

        memcpy(&packet->ntp,
               packet->payload + *offset,
               sizeof(Ntp));

        packet->ntp.root_delay = ntohl(packet->ntp.root_delay);
        packet->ntp.root_dispersion = ntohl(packet->ntp.root_dispersion);
        packet->ntp.reference_timestamp = be64toh(packet->ntp.reference_timestamp);
        packet->ntp.originate_timestamp = be64toh(packet->ntp.originate_timestamp);
        packet->ntp.receive_timestamp = be64toh(packet->ntp.receive_timestamp);
        packet->ntp.transmit_timestamp = be64toh(packet->ntp.transmit_timestamp);

        *offset += sizeof(Ntp);
    }

    return 0;
}