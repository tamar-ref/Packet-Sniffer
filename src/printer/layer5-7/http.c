#include "../../../headers/printer/layer5-7/http.h"

void print_http(Http http)
{
       printf("\n");
       print_string_field("Protocol", "HTTP", 0);

       if (http.is_request)
       {
              print_string_field("Method", http.method, 0);
              print_string_field("URI", http.uri, 0);
              print_string_field("Version", http.version, 0);
       }
       else if (http.is_response)
       {
              print_string_field("Version", http.version, 0);
              print_uint_field("Status Code", http.status_code, 0);
              print_string_field("Status Text", http.status_text, 0);
       }

       printf("Headers\n");

       for (int i = 0; i < http.header_count; i++)
       {
              print_string_field(http.headers[i].name, http.headers[i].value, 0);
       }
}