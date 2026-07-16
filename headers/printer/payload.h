#ifndef PAYLOAD_PRINTER_H
#define PAYLOAD_PRINTER_H

#include <stdio.h>

void print_hex(const unsigned char *data, size_t length);
void print_ascii(const unsigned char *data, size_t length);
void print_payload(const unsigned char *data, size_t length);

#endif