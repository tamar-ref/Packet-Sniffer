#ifndef PRINTER_UTILS_H
#define PRINTER_UTILS_H

#include <stdio.h>
#include <stdint.h>

#include "define.h"
#include "utils.h"

void print_label(const char *label, int is_sub_field);
void print_uint_field(const char *label, unsigned int value, int is_sub_field);
void print_uint_bytes_field(const char *label, unsigned int value, int is_sub_field);
void print_hex_field(const char *label, unsigned int value, int digits, int is_sub_field);
void print_string_field(const char *label, char *value, int is_sub_field);
void print_data(const char *label, int data_length, uint8_t data[data_length], int is_sub_field);
void print_ip_field(const char *label, uint8_t ip[IP_ADDRESS_SIZE], int is_sub_field);
void print_mac_field(const char *label, uint8_t mac[MAC_ADDRESS_SIZE], int is_sub_field);
void print_address_field(const char *label, uint8_t address[ADDRESS_SIZE], int is_sub_field);
void print_bits_field(const char *label, uint16_t value, int digits, int is_sub_field);
void print_timestamp_field(const char *label, uint64_t value, int is_sub_field);

#endif