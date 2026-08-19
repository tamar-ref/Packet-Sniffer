#include "../../../headers/printer/layer5-7/http.h"

void print_http(Http http)
{
    printf("\n%-*s: HTTP\n",
           PRINT_LABEL_WIDTH,
           "Protocol");

    if (http.is_request)
    {
        printf("%-*s: %s\n",
               PRINT_LABEL_WIDTH,
               "Method",
               http.method);

        printf("%-*s: %s\n",
               PRINT_LABEL_WIDTH,
               "URI",
               http.uri);

        printf("%-*s: %s\n",
               PRINT_LABEL_WIDTH,
               "Version",
               http.version);
    }
    else if (http.is_response)
    {
        printf("%-*s: %s\n",
               PRINT_LABEL_WIDTH,
               "Version",
               http.version);

        printf("%-*s: %d\n",
               PRINT_LABEL_WIDTH,
               "Status Code",
               http.status_code);

        printf("%-*s: %s\n",
               PRINT_LABEL_WIDTH,
               "Status Text",
               http.status_text);
    }

    printf("Headers\n");

    for (int i = 0; i < http.header_count; i++)
    {
        printf("%-*s: %s\n",
               PRINT_LABEL_WIDTH,
               http.headers[i].name,
               http.headers[i].value);
    }
}