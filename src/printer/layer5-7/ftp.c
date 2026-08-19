#include "../../../headers/printer/layer5-7/ftp.h"

void print_ftp(Ftp ftp)
{
    printf("\n%-*s: FTP\n",
           PRINT_LABEL_WIDTH,
           "Protocol");

    if (ftp.is_request)
    {
        printf("%-*s: %s\n",
               PRINT_LABEL_WIDTH,
               "Command",
               ftp.command);

        if (ftp.argument[0] != '\0')
        {
            printf("%-*s: %s\n",
                   PRINT_LABEL_WIDTH,
                   "Argument",
                   ftp.argument);
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
        printf("%-*s: %d\n",
               PRINT_LABEL_WIDTH,
               "Status Code",
               ftp.status_code);
        printf("%-*s: %s\n",
               PRINT_LABEL_WIDTH,
               "Status Text",
               ftp.status_text);
    }
}
