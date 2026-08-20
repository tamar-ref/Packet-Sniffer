#ifndef PRINTER_UTILS_H
#define PRINTER_UTILS_H

#include <stdio.h>
#include <stdint.h>

#include "define.h"
#include "utils.h"

void print_protocol_name(const char *protocol_name);
void print_uint_field(const char *label, unsigned int value);
void print_uint_bytes_field(const char *label, unsigned int value);
void print_hex_field(const char *label, unsigned int value, int digits);
void print_string_field(const char *label, char *value);
void print_sub_uint_field(const char *sub_label, unsigned int value);
void print_sub_hex_field(const char *sub_label, unsigned int value, int digits);
void print_sub_string_field(const char *sub_label, char *value);
void print_ip_field(const char *label, uint8_t ip[IP_ADDRESS_SIZE]);
void print_mac_field(const char *label, uint8_t mac[MAC_ADDRESS_SIZE]);
void print_address_field(const char *label, uint8_t address[ADDRESS_SIZE]);
void print_bits_field(const char *label, uint16_t value, int digits);
void print_timestamp_field(const char *label, uint64_t value);

#endif