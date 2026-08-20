#include "../../headers/common/printer_utils.h"

void print_protocol_name(const char *protocol_name)
{
    printf("\n%-*s: %s\n",
           PRINT_LABEL_WIDTH,
           "Protocol",
           protocol_name);
}

void print_uint_field(const char *label, unsigned int value)
{
    printf("%-*s: %u\n",
           PRINT_LABEL_WIDTH,
           label,
           value);
}

void print_uint_bytes_field(const char *label, unsigned int value)
{
    printf("%-*s: %u bytes\n",
           PRINT_LABEL_WIDTH,
           label,
           value);
}

void print_hex_field(const char *label, unsigned int value, int digits)
{
    printf("%-*s: 0x%0*X\n",
           PRINT_LABEL_WIDTH,
           label,
           digits,
           value);
}

void print_string_field(const char *label, char *value)
{
    printf("%-*s: %s\n",
           PRINT_LABEL_WIDTH,
           label,
           value);
}

void print_sub_uint_field(const char *sub_label, unsigned int value)
{
    printf("%-*s%-*s: %u\n",
           SUB_LABEL_WIDTH,
           "",
           PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH,
           sub_label,
           value);
}

void print_sub_hex_field(const char *sub_label, unsigned int value, int digits)
{
    printf("%-*s%-*s: 0x%0*X\n",
           SUB_LABEL_WIDTH,
           "",
           PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH,
           sub_label,
           digits,
           value);
}

void print_sub_string_field(const char *sub_label, char *value)
{
    printf("%-*s%-*s: %s\n",
           SUB_LABEL_WIDTH,
           "",
           PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH,
           sub_label,
           value);
}

void print_ip_field(const char *label, uint8_t ip[IP_ADDRESS_SIZE])
{
    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           label);
    print_ip(ip);
    printf("\n");
}

void print_mac_field(const char *label, uint8_t mac[MAC_ADDRESS_SIZE])
{
    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           label);
    print_mac(mac);
    printf("\n");
}

void print_address_field(const char *label, uint8_t address[ADDRESS_SIZE])
{
    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           label);
    print_address(address);
    printf("\n");
}

void print_bits_field(const char *label, uint16_t value, int digits)
{
    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           label);
    print_bits(value, digits);
    printf("\n");
}

void print_timestamp_field(const char *label, uint64_t value)
{
    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           label);
    print_timestamp(value);
    printf("\n");
}