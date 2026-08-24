#include "../../headers/common/printer_utils.h"

void print_label(const char *label, int is_sub_field)
{
    if (is_sub_field)
    {
        printf("%-*s%-*s: ",
               SUB_LABEL_WIDTH,
               "",
               PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH,
               label);
    }
    else
    {
        printf("%-*s: ",
               PRINT_LABEL_WIDTH,
               label);
    }
}

void print_uint_field(const char *label, unsigned int value, int is_sub_field)
{
    print_label(label, is_sub_field);
    printf("%u\n", value);
}

void print_uint_bytes_field(const char *label, unsigned int value, int is_sub_field)
{
    print_label(label, is_sub_field);
    printf("%u bytes\n", value);
}

void print_hex_field(const char *label, unsigned int value, int digits, int is_sub_field)
{
    print_label(label, is_sub_field);
    printf("0x%0*X\n", digits, value);
}

void print_string_field(const char *label, char *value, int is_sub_field)
{
    print_label(label, is_sub_field);
    printf("%s\n", value);
}

void print_data(const char *label, int data_length, uint8_t data[data_length], int is_sub_field)
{
    print_label(label, is_sub_field);
    for (int i = 0; i < data_length; i++)
    {
        printf("%02X ", data[i]);
    }
    printf("\n");
}

void print_ip_field(const char *label, uint8_t ip[IP_ADDRESS_SIZE], int is_sub_field)
{
    print_label(label, is_sub_field);
    print_ip(ip);
    printf("\n");
}

void print_mac_field(const char *label, uint8_t mac[MAC_ADDRESS_SIZE], int is_sub_field)
{
    print_label(label, is_sub_field);
    print_mac(mac);
    printf("\n");
}

void print_address_field(const char *label, uint8_t address[ADDRESS_SIZE], int is_sub_field)
{
    print_label(label, is_sub_field);
    print_address(address);
    printf("\n");
}

void print_bits_field(const char *label, uint16_t value, int digits, int is_sub_field)
{
    print_label(label, is_sub_field);
    print_bits(value, digits);
    printf("\n");
}

void print_timestamp_field(const char *label, uint64_t value, int is_sub_field)
{
    print_label(label, is_sub_field);
    print_timestamp(value);
    printf("\n");
}