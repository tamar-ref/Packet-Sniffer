#include "../../../headers/parser/layer5-7/ftp.h"

int is_ftp_request(Packet *packet, size_t *offset)
{
    const char *commands[] =
        {
            "USER ",
            "PASS ",
            "ACCT ",
            "CWD ",
            "CDUP ",
            "QUIT ",
            "PORT ",
            "PASV ",
            "TYPE ",
            "RETR ",
            "STOR ",
            "LIST ",
            "NLST ",
            "DELE ",
            "RMD ",
            "MKD ",
            "PWD ",
            "SYST ",
            "NOOP "};
    int command_count = sizeof(commands) / sizeof(commands[0]);

    for (int i = 0; i < command_count; i++)
    {
        if (memcmp(
                packet->payload + *offset,
                commands[i],
                strlen(commands[i])) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int is_ftp_response(Packet *packet, size_t *offset)
{
    if (*offset + 4 > packet->length)
    {
        return 0;
    }

    char *data = (char *)(packet->payload + *offset);

    if (data[0] < '0' || data[0] > '9')
    {
        return 0;
    }

    if (data[1] < '0' || data[1] > '9')
    {
        return 0;
    }

    if (data[2] < '0' || data[2] > '9')
    {
        return 0;
    }

    if (data[3] != ' ')
    {
        return 0;
    }

    return 1;
}

int parse_ftp_request(Packet *packet, size_t *offset)
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

    size_t line_length = line_end - data;

    char *space = memchr(data, ' ', line_length);
    if (space == NULL)
    {
        return -1;
    }

    size_t command_length = space - data;
    memcpy(
        packet->ftp.command,
        data,
        command_length);
    packet->ftp.command[command_length] = '\0';

    char *argument_start = space + 1;
    size_t argument_length = line_end - argument_start;
    if (argument_length >= sizeof(packet->ftp.argument))
    {
        return -1;
    }

    memcpy(
        packet->ftp.argument,
        argument_start,
        argument_length);

    packet->ftp.argument[argument_length] = '\0';
    *offset += line_length + 2;

    return 0;
}

int parse_ftp_response(Packet *packet, size_t *offset)
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

    size_t line_length = line_end - data;

    char status_code_string[4];
    memcpy(
        status_code_string,
        data,
        3);
    status_code_string[3] = '\0';
    packet->ftp.status_code = atoi(status_code_string);

    char *status_text_start = data + 4;
    size_t status_text_length = line_end - status_text_start;
    if (status_text_length >= sizeof(packet->ftp.status_text))
    {
        return -1;
    }

    memcpy(
        packet->ftp.status_text,
        status_text_start,
        status_text_length);
    packet->ftp.status_text[status_text_length] ='\0';

    *offset += line_length + 2;

    return 0;
}

int parse_ftp(Packet *packet, size_t *offset)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    if (is_ftp_request(packet, offset))
    {
        packet->has_ftp = 1;
        packet->ftp.is_request = 1;
        packet->ftp.is_response = 0;
        return parse_ftp_request(packet, offset);
    }

    if (is_ftp_response(packet, offset))
    {
        packet->has_ftp = 1;
        packet->ftp.is_request = 0;
        packet->ftp.is_response = 1;
        return parse_ftp_response(packet, offset);
    }

    return 0;
}