#include "../../../headers/printer/layer5-7/ftp.h"

void print_ftp(Ftp ftp)
{
       printf("\n");
       print_string_field("Protocol", "FTP", 0);

       if (ftp.is_request)
       {
              print_string_field("Command", ftp.command, 0);

              if (ftp.argument[0] != '\0')
              {
                     print_string_field("Argument", ftp.argument, 0);
              }
              else
              {
                     print_string_field("Argument", "None", 0);
              }
       }
       else if (ftp.is_response)
       {
              print_uint_field("Status Code", ftp.status_code, 0);
              print_string_field("Status Text", ftp.status_text, 0);
       }
}
