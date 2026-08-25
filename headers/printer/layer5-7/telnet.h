#ifndef TELNET_PRINTER_H
#define TELNET_PRINTER_H

#include <stdio.h>

#include "../../common/types/layer5-7.h"
#include "../../common/define.h"
#include "../../common/printer_utils.h"

char *telnet_command_name(uint8_t command);
void print_telnet(Telnet telnet);

#endif