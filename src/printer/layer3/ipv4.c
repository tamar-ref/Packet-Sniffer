#include "../../../headers/printer/layer3/ipv4.h"

void print_ipv4(IPv4 ipv4)
{
    uint8_t version = ipv4.version_ihl >> 4;
    uint8_t ihl = ipv4.version_ihl & 0x0F;

    uint16_t flags = (ipv4.flags_fragment_offset >> 13) & 0x07;
    uint16_t fragment_offset = ipv4.flags_fragment_offset & 0x1FFF;

    uint8_t reserved = (flags >> 2) & 1;
    uint8_t df = (flags >> 1) & 1;
    uint8_t mf = flags & 1;

    printf("\n%-*s: IPv4\n",
           PRINT_LABEL_WIDTH,
           "Protocol");

    printf("%-*s: %u\n",
           PRINT_LABEL_WIDTH,
           "Version",
           version);

    printf("%-*s: %u bytes\n",
           PRINT_LABEL_WIDTH,
           "IHL",
           ihl * 4);

    printf("%-*s: 0x%04X\n",
           PRINT_LABEL_WIDTH,
           "Total Length",
           ipv4.total_length);

    printf("%-*s: 0x%04X\n",
           PRINT_LABEL_WIDTH,
           "Identification",
           ipv4.identification);

    printf("Flags\n");

    printf("%-*s%-*s: %d\n",
           SUB_LABEL_WIDTH,
           "",
           PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH,
           "Reserved",
           reserved);

    printf("%-*s%-*s: %d\n",
           SUB_LABEL_WIDTH,
           "",
           PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH,
           "DF",
           df);

    printf("%-*s%-*s: %d\n",
           SUB_LABEL_WIDTH,
           "",
           PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH,
           "MF",
           mf);

    printf("%-*s: %u\n",
           PRINT_LABEL_WIDTH,
           "Fragment Offset",
           fragment_offset * 8);

    printf("%-*s: 0x%02x\n",
           PRINT_LABEL_WIDTH,
           "TTL",
           ipv4.ttl);

    printf("%-*s: 0x%02x\n",
           PRINT_LABEL_WIDTH,
           "Protocol",
           ipv4.protocol);

    printf("%-*s: 0x%02x\n",
           PRINT_LABEL_WIDTH,
           "Header Checksum",
           ipv4.header_checksum);

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Source IP Address");
    print_ip(ipv4.source_ip);
    printf("\n");

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Destination IP Address");
    print_ip(ipv4.destination_ip);
    printf("\n");

    if (ihl > 5)
    {
        int options_length = (ihl - 5) * 4;

        char options_string[PRINT_LABEL_WIDTH];

        snprintf(options_string,
                 sizeof(options_string),
                 "Options (%d bytes)",
                 options_length);

        printf("%-*s: ",
               PRINT_LABEL_WIDTH,
               options_string);

        for (int i = 0; i < options_length; i++)
        {
            printf("%02X ",
                   ipv4.options[i]);
        }
        printf("\n");
    }
    else
    {
        printf("%-*s: None\n",
               PRINT_LABEL_WIDTH,
               "Options");
    }
}