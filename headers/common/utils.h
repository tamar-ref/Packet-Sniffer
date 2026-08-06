#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdint.h>

#include "define.h"

void print_mac(unsigned char mac[MAC_ADDRESS_SIZE]);
void print_ip(unsigned char ip[IP_ADDRESS_SIZE]);
void print_address(uint8_t address[ADDRESS_SIZE]);
void print_bits(uint16_t value, int bits);

#endif