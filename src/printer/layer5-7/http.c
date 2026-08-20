#include "../../../headers/printer/layer5-7/http.h"

void print_http(Http http)
{
       print_protocol_name("HTTP");

       if (http.is_request)
       {
              print_string_field("Method", http.method);
              print_string_field("URI", http.uri);
              print_string_field("Version", http.version);
       }
       else if (http.is_response)
       {
              print_string_field("Version", http.version);
              print_uint_field("Status Code", http.status_code);
              print_string_field("Status Text", http.status_text);
       }

       printf("Headers\n");

       for (int i = 0; i < http.header_count; i++)
       {
              print_string_field(http.headers[i].name, http.headers[i].value);
       }
}