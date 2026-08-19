#include "../../../headers/printer/layer5-7/https.h"

void print_https(Tls tls)
{
    printf("\n%-*s: HTTPS\n",
           PRINT_LABEL_WIDTH,
           "Protocol");

    printf("%-*s: 0x%02X",
           PRINT_LABEL_WIDTH,
           "Content Type",
           tls.content_type);

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

    printf("%-*s: 0x%04X\n",
           PRINT_LABEL_WIDTH,
           "Version",
           tls.version);

    printf("%-*s: %u bytes\n",
           PRINT_LABEL_WIDTH,
           "Length",
           tls.length);

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Fragment");

    for (int i = 0; i < tls.length; i++)
    {
        printf("%02X ",
               tls.fragment[i]);
    }
    printf("\n");
}
