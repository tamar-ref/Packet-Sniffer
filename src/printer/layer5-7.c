#include "../../headers/printer/layer5-7.h"

void print_http(Http http)
{
    printf("\n%-*s: HTTP\n", PRINT_LABEL_WIDTH, "Protocol");

    if (http.is_request)
    {
        printf("%-*s: %s\n", PRINT_LABEL_WIDTH, "Method", http.method);
        printf("%-*s: %s\n", PRINT_LABEL_WIDTH, "URI", http.uri);
        printf("%-*s: %s\n", PRINT_LABEL_WIDTH, "Version", http.version);
    }
    else if (http.is_response)
    {
        printf("%-*s: %s\n", PRINT_LABEL_WIDTH, "Version", http.version);
        printf("%-*s: %d\n", PRINT_LABEL_WIDTH, "Status Code", http.status_code);
        printf("%-*s: %s\n", PRINT_LABEL_WIDTH, "Status Text", http.status_text);
    }

    printf("Headers\n");

    for (int i = 0; i < http.header_count; i++)
    {
        printf("%-*s: %s\n", PRINT_LABEL_WIDTH, http.headers[i].name, http.headers[i].value);
    }
}

void print_https(Tls tls)
{
    printf("\n%-*s: HTTPS\n", PRINT_LABEL_WIDTH, "Protocol");

    printf("%-*s: 0x%02X", PRINT_LABEL_WIDTH, "Content Type", tls.content_type);
    switch (tls.content_type)
    {
    case 0x14:
        printf(" (Change Cipher Spec)\n");
        break;

    case 0x15:
        printf(" (Alert)\n");
        break;

    case 0x16:
        printf(" (Handshake)\n");
        break;

    case 0x17:
        printf(" (Application Data)\n");
        break;

    default:
        printf(" (Unknown)\n");
        break;
    }

    printf("%-*s: 0x%04X\n", PRINT_LABEL_WIDTH, "Version", tls.version);
    printf("%-*s: %u bytes\n", PRINT_LABEL_WIDTH, "Length", tls.length);
    
    printf("%-*s: ", PRINT_LABEL_WIDTH, "Fragment");
    for (int i = 0; i < tls.length; i++)
    {
        printf("%02X ", tls.fragment[i]);
    }
    printf("\n");
}

void print_layer5_7(Packet packet)
{
    printf("\nLayer 5-7\n");
    printf("-------------------------\n");

    if (packet.has_http)
    {
        print_http(packet.http);
    }
    if (packet.has_tls)
    {
        print_https(packet.tls);
    }
}