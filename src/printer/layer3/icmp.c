#include "../../../headers/printer/layer3/icmp.h"

void print_icmp(Icmp icmp)
{
    printf("\n%-*s: ICMP\n",
           PRINT_LABEL_WIDTH,
           "Protocol");

    printf("%-*s: 0x%02x\n",
           PRINT_LABEL_WIDTH,
           "Type",
           icmp.type);

    printf("%-*s: 0x%02x\n",
           PRINT_LABEL_WIDTH,
           "Code",
           icmp.code);

    printf("%-*s: 0x%04x\n",
           PRINT_LABEL_WIDTH,
           "Checksum",
           icmp.checksum);

    printf("%-*s: 0x%08x\n",
           PRINT_LABEL_WIDTH,
           "Rest Of Header",
           icmp.rest_of_header);
}
