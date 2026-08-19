#include "../../../headers/printer/layer3/icmpv6.h"

void print_icmpv6(Icmpv6 icmpv6)
{
    printf("\n%-*s: ICMPv6\n",
           PRINT_LABEL_WIDTH,
           "Protocol");

    printf("%-*s: 0x%02x\n",
           PRINT_LABEL_WIDTH,
           "Type",
           icmpv6.type);

    printf("%-*s: 0x%02x\n",
           PRINT_LABEL_WIDTH,
           "Code",
           icmpv6.code);

    printf("%-*s: 0x%04x\n",
           PRINT_LABEL_WIDTH,
           "Checksum",
           icmpv6.checksum);

    printf("%-*s: 0x%08x\n",
           PRINT_LABEL_WIDTH,
           "Message Body",
           icmpv6.message_body);
}