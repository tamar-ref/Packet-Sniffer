#include "../../../headers/parser/layer4/tcp.h"

int parse_tcp(Packet *packet, size_t *offset)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    packet->has_tcp = 1;

    memcpy(&packet->tcp.source_port,
           packet->payload + *offset,
           sizeof(packet->tcp.source_port));
    packet->tcp.source_port = ntohs(packet->tcp.source_port);
    *offset += sizeof(packet->tcp.source_port);

    memcpy(&packet->tcp.destination_port,
           packet->payload + *offset,
           sizeof(packet->tcp.destination_port));
    packet->tcp.destination_port = ntohs(packet->tcp.destination_port);
    *offset += sizeof(packet->tcp.destination_port);

    memcpy(&packet->tcp.sequence_number,
           packet->payload + *offset,
           sizeof(packet->tcp.sequence_number));
    packet->tcp.sequence_number = ntohl(packet->tcp.sequence_number);
    *offset += sizeof(packet->tcp.sequence_number);

    memcpy(&packet->tcp.acknowledgment_number,
           packet->payload + *offset,
           sizeof(packet->tcp.acknowledgment_number));
    packet->tcp.acknowledgment_number = ntohl(packet->tcp.acknowledgment_number);
    *offset += sizeof(packet->tcp.acknowledgment_number);

    memcpy(&packet->tcp.data_offset_reserved_flags,
           packet->payload + *offset,
           sizeof(packet->tcp.data_offset_reserved_flags));
    packet->tcp.data_offset_reserved_flags = ntohs(packet->tcp.data_offset_reserved_flags);
    *offset += sizeof(packet->tcp.data_offset_reserved_flags);

    memcpy(&packet->tcp.window_size,
           packet->payload + *offset,
           sizeof(packet->tcp.window_size));
    packet->tcp.window_size = ntohs(packet->tcp.window_size);
    *offset += sizeof(packet->tcp.window_size);

    memcpy(&packet->tcp.checksum,
           packet->payload + *offset,
           sizeof(packet->tcp.checksum));
    packet->tcp.checksum = ntohs(packet->tcp.checksum);
    *offset += sizeof(packet->tcp.checksum);

    memcpy(&packet->tcp.urgent_pointer,
           packet->payload + *offset,
           sizeof(packet->tcp.urgent_pointer));
    packet->tcp.urgent_pointer = ntohs(packet->tcp.urgent_pointer);
    *offset += sizeof(packet->tcp.urgent_pointer);

    uint16_t data_offset = (packet->tcp.data_offset_reserved_flags >> 12) & 0x0F;
    if (data_offset > 5)
    {
        memcpy(&packet->tcp.options,
               packet->payload + *offset,
               (data_offset - 5) * 4);
        *offset += (data_offset - 5) * 4;
    }

    return 0;
}