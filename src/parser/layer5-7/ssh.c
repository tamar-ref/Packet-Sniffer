#include "../../../headers/parser/layer5-7/ssh.h"

int is_ssh_identification(Packet *packet, size_t *offset)
{
    const char *ssh_version = "SSH-";
    size_t version_length = strlen(ssh_version);

    if (*offset + version_length > packet->length)
    {
        return 0;
    }

    if (memcmp(
            packet->payload + *offset,
            ssh_version,
            version_length) == 0)
    {
        return 1;
    }

    return 0;
}

int is_ssh_packet(Packet *packet, size_t *offset)
{
    if (*offset + 5 > packet->length)
    {
        return 0;
    }

    uint32_t packet_length;

    memcpy(
        &packet_length,
        packet->payload + *offset,
        sizeof(packet_length));

    packet_length = ntohl(packet_length);

    uint8_t padding_length = packet->payload[*offset + 4];

    if (packet_length < 2 ||
        padding_length < 4 ||
        padding_length >= packet_length ||
        *offset + 4 + packet_length > packet->length)
    {
        return 0;
    }

    return 1;
}

int parse_ssh_identification(Packet *packet, size_t *offset)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    char *data = (char *)(packet->payload + *offset);

    char *line_end = strstr(data, "\r\n");

    if (line_end == NULL)
    {
        return -1;
    }

    size_t length = line_end - data;

    memcpy(
        packet->ssh.identification,
        data,
        length);

    packet->ssh.identification[length] = '\0';

    *offset += length + 2;

    return 0;
}

int parse_ssh_packet(Packet *packet, size_t *offset)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    size_t basic_ssh_size = sizeof(packet->ssh.packet_length) + sizeof(packet->ssh.padding_length);

    memcpy(
        &packet->ssh.packet_length,
        packet->payload + *offset,
        basic_ssh_size);
    packet->ssh.packet_length = ntohl(packet->ssh.packet_length);
    *offset += basic_ssh_size;

    packet->ssh.payload_length = packet->ssh.packet_length - 1 - packet->ssh.padding_length;

    packet->ssh.message_type = packet->payload[*offset];

    memcpy(
        packet->ssh.payload,
        packet->payload + *offset,
        packet->ssh.payload_length);
    *offset += packet->ssh.payload_length;

    memcpy(
        packet->ssh.padding,
        packet->payload + *offset,
        packet->ssh.padding_length);
    *offset += packet->ssh.padding_length;

    return 0;
}

int parse_ssh(Packet *packet, size_t *offset)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    if (is_ssh_identification(packet, offset))
    {
        packet->has_ssh = 1;
        packet->ssh.is_identification = 1;
        return parse_ssh_identification(packet, offset);
    }

    if (is_ssh_packet(packet, offset))
    {
        packet->has_ssh = 1;
        packet->ssh.is_identification = 0;
        return parse_ssh_packet(packet, offset);
    }

    return -1;
}