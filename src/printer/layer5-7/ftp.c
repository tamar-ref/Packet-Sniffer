#include "../../../headers/printer/layer5-7/ftp.h"

void print_ftp(Ftp ftp)
{
       print_protocol_name("FTP");

       if (ftp.is_request)
       {
              print_string_field("Command", ftp.command);

              if (ftp.argument[0] != '\0')
              {
                     print_string_field("Argument", ftp.argument);
              }
              else
              {
                     printf("%-*s: None\n",
                            PRINT_LABEL_WIDTH,
                            "Argument");
              }
       }
       else if (ftp.is_response)
       {
              print_uint_field("Status Code", ftp.status_code);
              print_string_field("Status Text", ftp.status_text);
       }
}
