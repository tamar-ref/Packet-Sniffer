#include "../../../headers/printer/layer5-7/https.h"

void print_https(Tls tls)
{
    print_protocol_name("HTTPS");
    print_hex_field("Content Type", tls.content_type, 2);

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

    print_hex_field("Version", tls.version, 4);
    print_uint_bytes_field("Length", tls.length);

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Fragment");

    for (int i = 0; i < tls.length; i++)
    {
        printf("%02X ", tls.fragment[i]);
    }
    printf("\n");
}
