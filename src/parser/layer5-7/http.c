#include "../../../headers/parser/layer5-7/http.h"

int is_http_request(Packet *packet, size_t *offset)
{
    const char *methods[] =
        {
            "GET ",
            "POST ",
            "PUT ",
            "DELETE ",
            "HEAD ",
            "OPTIONS ",
            "PATCH "};
    int method_count = sizeof(methods) / sizeof(methods[0]);

    for (int i = 0; i < method_count; i++)
    {
        if (memcmp(packet->payload + *offset,
                   methods[i],
                   strlen(methods[i])) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int is_http_response(Packet *packet, size_t *offset)
{
    const char *versions[] =
        {
            "HTTP/1.0 ",
            "HTTP/1.1 "};

    int version_count = sizeof(versions) / sizeof(versions[0]);
    for (int i = 0; i < version_count; i++)
    {
        if (memcmp(packet->payload + *offset,
                   versions[i],
                   strlen(versions[i])) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int parse_http_headers(Packet *packet, size_t *offset)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    char *data = (char *)(packet->payload + *offset);
    packet->http.header_count = 0;

    while (packet->http.header_count < MAX_HTTP_HEADERS)
    {
        if (data[0] == '\r' && data[1] == '\n')
        {
            *offset += 2;
            return 0;
        }

        char *line_end = strstr(data, "\r\n");
        if (line_end == NULL)
        {
            return -1;
        }
        size_t line_length = line_end - data;
        char *colon = memchr(data, ':', line_length);
        if (colon == NULL)
        {
            return -1;
        }

        size_t name_length = colon - data;
        if (name_length >= sizeof(packet->http.headers[0].name))
        {
            return -1;
        }
        memcpy(
            packet->http.headers[packet->http.header_count].name,
            data,
            name_length);
        packet->http.headers[packet->http.header_count].name[name_length] = '\0';

        char *value_start = colon + 1;
        while (value_start < line_end && *value_start == ' ')
        {
            value_start++;
        }
        size_t value_length = line_end - value_start;
        if (value_length >= sizeof(packet->http.headers[0].value))
        {
            return -1;
        }
        memcpy(
            packet->http.headers[packet->http.header_count].value,
            value_start,
            value_length);
        packet->http.headers[packet->http.header_count].value[value_length] = '\0';

        packet->http.header_count++;
        *offset += line_length + 2;
        data = (char *)(packet->payload + *offset);
    }

    return -1;
}

int parse_http_request(Packet *packet, size_t *offset)
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

    char *first_space = memchr(data, ' ', line_length);
    if (first_space == NULL)
    {
        return -1;
    }
    char *second_space = memchr(first_space + 1,
                                ' ',
                                line_end - (first_space + 1));
    if (second_space == NULL)
    {
        return -1;
    }

    size_t method_length = first_space - data;
    if (method_length >= sizeof(packet->http.method))
    {
        return -1;
    }
    memcpy(packet->http.method,
           data,
           method_length);
    packet->http.method[method_length] = '\0';

    size_t uri_length = second_space - (first_space + 1);
    if (uri_length >= sizeof(packet->http.uri))
    {
        return -1;
    }
    memcpy(packet->http.uri,
           first_space + 1,
           uri_length);
    packet->http.uri[uri_length] = '\0';

    size_t version_length = line_end - (second_space + 1);
    if (version_length >= sizeof(packet->http.version))
    {
        return -1;
    }
    memcpy(packet->http.version,
           second_space + 1,
           version_length);
    packet->http.version[version_length] = '\0';

    *offset += line_length + 2;

    if (parse_http_headers(packet, offset) != 0)
    {
        return -1;
    }

    return 0;
}

int parse_http_response(Packet *packet, size_t *offset)
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
    char *first_space = memchr(data, ' ', line_length);

    if (first_space == NULL)
    {
        return -1;
    }
    char *second_space = memchr(first_space + 1,
                                ' ',
                                line_end - (first_space + 1));
    if (second_space == NULL)
    {
        return -1;
    }

    size_t version_length = first_space - data;
    if (version_length >= sizeof(packet->http.version))
    {
        return -1;
    }
    memcpy(packet->http.version,
           data,
           version_length);
    packet->http.version[version_length] = '\0';
    size_t status_code_length = second_space - (first_space + 1);

    if (status_code_length != 3)
    {
        return -1;
    }
    char status_code_string[4];
    memcpy(status_code_string,
           first_space + 1,
           3);
    status_code_string[3] = '\0';
    packet->http.status_code = (int)atoi(status_code_string);

    size_t status_text_length = line_end - (second_space + 1);
    if (status_text_length >= sizeof(packet->http.status_text))
    {
        return -1;
    }
    memcpy(packet->http.status_text, second_space + 1, status_text_length);
    packet->http.status_text[status_text_length] = '\0';

    *offset += line_length + 2;

    if (parse_http_headers(packet, offset) != 0)
    {
        return -1;
    }

    return 0;
}

int parse_http(Packet *packet, size_t *offset)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    packet->has_http = 1;

    if (is_http_request(packet, offset))
    {
        packet->http.is_request = 1;
        packet->http.is_response = 0;
        if (parse_http_request(packet, offset) != 0)
        {
            return -1;
        }
        return 0;
    }

    if (is_http_response(packet, offset))
    {
        packet->http.is_request = 0;
        packet->http.is_response = 1;
        if (parse_http_response(packet, offset) != 0)
        {
            return -1;
        }
        return 0;
    }

    return -1;
}