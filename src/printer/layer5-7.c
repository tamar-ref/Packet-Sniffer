#include "../../headers/printer/layer5-7.h"

void print_http(Http http)
{
    printf("\nProtocol                : HTTP\n");

    if (http.is_request)
    {
        printf("Method                  : %s\n", http.method);
        printf("URI                     : %s\n", http.uri);
        printf("Version                 : %s\n", http.version);
    }
    else if (http.is_response)
    {
        printf("Version                 : %s\n", http.version);
        printf("Stat code               : %d\n", http.status_code);
        printf("Status text             : %s\n", http.status_text);
    }

    printf("Headers\n");

    for (int i = 0; i < http.header_count; i++)
    {
        printf("%-24s: %s\n",
               http.headers[i].name,
               http.headers[i].value);
    }
}

void print_layer5_7(Packet packet)
{
    printf("\nLayer 5-7\n");
    printf("-------------------------\n");

    if (packet.has_http)
    {
        print_http(packet.http);
    }
}