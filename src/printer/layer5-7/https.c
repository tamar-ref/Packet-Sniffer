#include "../../../headers/printer/layer5-7/https.h"

void print_https(Tls tls)
{
    printf("\n");
    print_string_field("Protocol", "HTTPS", 0);

    printf("%-*s: 0x%02x",
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

    print_hex_field("Version", tls.version, 4, 0);
    print_uint_bytes_field("Length", tls.length, 0);
    print_data("Fragment", tls.length, tls.fragment, 0);
}
