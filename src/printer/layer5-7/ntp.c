#include "../../../headers/printer/layer5-7/ntp.h"

double ntp_fixed_to_seconds(uint32_t value)
{
    return (double)value / 65536.0;
}

void print_ntp(Ntp ntp)
{
    uint8_t li = (ntp.li_version_mode >> 6) & 0x03;
    uint8_t version = (ntp.li_version_mode >> 3) & 0x07;
    uint8_t mode = ntp.li_version_mode & 0x07;

    printf("\n%-*s: NTP\n",
           PRINT_LABEL_WIDTH,
           "Protocol");

    printf("%-*s: %u\n",
           PRINT_LABEL_WIDTH,
           "Leap Indicator",
           li);

    printf("%-*s: %u\n",
           PRINT_LABEL_WIDTH,
           "Version",
           version);

    printf("%-*s: %u\n",
           PRINT_LABEL_WIDTH,
           "Mode",
           mode);

    printf("%-*s: %u\n",
           PRINT_LABEL_WIDTH,
           "Stratum",
           ntp.stratum);

    printf("%-*s: %u\n",
           PRINT_LABEL_WIDTH,
           "Poll",
           ntp.poll);

    printf("%-*s: 0x%02x\n",
           PRINT_LABEL_WIDTH,
           "Precision",
           ntp.precision);

    printf("%-*s: %.6f seconds\n",
           PRINT_LABEL_WIDTH,
           "Root Delay",
           ntp_fixed_to_seconds(ntp.root_delay));

    printf("%-*s: %.6f seconds\n",
           PRINT_LABEL_WIDTH,
           "Root Dispersion",
           ntp_fixed_to_seconds(ntp.root_dispersion));

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Reference ID");
    print_ip(ntp.reference_id);
    printf("\n");

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Reference Timestamp");
    print_timestamp(ntp.reference_timestamp);
    printf("\n");

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Origin Timestamp");
    print_timestamp(ntp.originate_timestamp);
    printf("\n");

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Receive Timestamp");
    print_timestamp(ntp.receive_timestamp);
    printf("\n");

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Transmit Timestamp");
    print_timestamp(ntp.transmit_timestamp);
    printf("\n");
}