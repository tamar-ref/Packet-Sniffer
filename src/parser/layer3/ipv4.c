#include "../../../headers/parser/layer3/ipv4.h"

int parse_ipv4(const unsigned char *buffer,
               size_t length,
               IPv4 *ipv4)
{
    if (length < IPV4_MIN_HEADER_SIZE)
    {
        return -1;
    }

    ipv4->version = buffer[0] >> 4;
    ipv4->header_length = (buffer[0] & 0x0F) * 4;
    ipv4->dscp = buffer[1] >> 2;
    ipv4->ecn = buffer[1] & 0x03;
    memcpy(&ipv4->total_length,
           buffer + 2,
           2);
    ipv4->total_length = ntohs(ipv4->total_length);
    memcpy(&ipv4->identification,
           buffer + 4,
           2);
    ipv4->identification = ntohs(ipv4->identification);

    unsigned short temp;
    memcpy(&temp,
           buffer + 6,
           2);
    temp = ntohs(temp);
    ipv4->flags = temp >> 13;
    ipv4->fragment_offset = temp & 0x1FFF;

    ipv4->ttl = buffer[8];
    ipv4->protocol = buffer[9];

    memcpy(&ipv4->header_checksum,
           buffer + 10,
           2);

    ipv4->header_checksum = ntohs(ipv4->header_checksum);
    memcpy(&ipv4->source_ip,
           buffer + 12,
           4);

    memcpy(&ipv4->destination_ip,
           buffer + 16,
           4);

    if (ipv4->header_length > 20)
    {
        printf("IPv4 Options exist\n");
    }
}