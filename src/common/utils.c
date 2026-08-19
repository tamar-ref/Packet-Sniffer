#include "../../headers/common/utils.h"

void print_mac(unsigned char mac[MAC_ADDRESS_SIZE])
{
    printf(
        "%02X:%02X:%02X:%02X:%02X:%02X",
        mac[0],
        mac[1],
        mac[2],
        mac[3],
        mac[4],
        mac[5]);
}

void print_ip(unsigned char ip[IP_ADDRESS_SIZE])
{
    printf(
        "%d.%d.%d.%d",
        ip[0],
        ip[1],
        ip[2],
        ip[3]);
}

void print_address(uint8_t address[ADDRESS_SIZE])
{
    for (int i = 0; i < ADDRESS_SIZE; i += 2)
    {
        uint16_t part =
            ((uint16_t)address[i] << 8) |
            address[i + 1];

        printf("%04x", part);

        if (i < ADDRESS_SIZE - 2)
        {
            printf(":");
        }
    }
}

void print_bits(uint16_t value, int bits)
{
    printf("0b");
    for (int i = bits - 1; i >= 0; i--)
    {
        printf("%u", (value >> i) & 1);
    }
}

const char *month_name(int month)
{
    const char *months[] =
        {
            "Jan", "Feb", "Mar", "Apr",
            "May", "Jun", "Jul", "Aug",
            "Sep", "Oct", "Nov", "Dec"};

    return months[month];
}

void print_timestamp(uint64_t timestamp)
{
    uint32_t seconds = timestamp >> 32;
    uint32_t fraction = timestamp & 0xFFFFFFFF;
    double fractional_seconds = (double)fraction / 4294967296.0;
    time_t unix_time = (time_t)(seconds - 2208988800UL);
    struct tm *utc = gmtime(&unix_time);

    if (utc == NULL)
    {
        printf("Invalid timestamp");
        return;
    }

    printf("%s %02d, %04d %02d:%02d:%02d.%09u UTC",
           month_name(utc->tm_mon),
           utc->tm_mday,
           utc->tm_year + 1900,
           utc->tm_hour,
           utc->tm_min,
           utc->tm_sec,
           (unsigned int)(fractional_seconds * 1000000000.0));
}