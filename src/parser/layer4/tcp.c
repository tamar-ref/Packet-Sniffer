#include "../../../headers/parser/layer4/tcp.h"

int parse_tcp(Packet *packet, size_t *offset, uint16_t *next_protocol)
{
       if (packet == NULL || offset == NULL)
       {
              return -1;
       }

       packet->has_tcp = 1;

       memcpy(&packet->tcp,
              packet->payload + *offset,
              sizeof(packet->tcp) - sizeof(packet->tcp.options));
       packet->tcp.source_port = ntohs(packet->tcp.source_port);
       packet->tcp.destination_port = ntohs(packet->tcp.destination_port);
       packet->tcp.sequence_number = ntohl(packet->tcp.sequence_number);
       packet->tcp.acknowledgment_number = ntohl(packet->tcp.acknowledgment_number);
       packet->tcp.data_offset_reserved_flags = ntohs(packet->tcp.data_offset_reserved_flags);
       packet->tcp.window_size = ntohs(packet->tcp.window_size);
       packet->tcp.checksum = ntohs(packet->tcp.checksum);
       packet->tcp.urgent_pointer = ntohs(packet->tcp.urgent_pointer);

       *offset += sizeof(packet->tcp) - sizeof(packet->tcp.options);

       uint16_t data_offset = (packet->tcp.data_offset_reserved_flags >> 12) & 0x0F;
       if (data_offset > 5)
       {
              memcpy(&packet->tcp.options,
                     packet->payload + *offset,
                     (data_offset - 5) * 4);
              *offset += (data_offset - 5) * 4;
       }

       *next_protocol = packet->tcp.destination_port;

       return 0;
}