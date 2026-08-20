#ifndef NTP_PRINTER_H
#define NTP_PRINTER_H

#include <stdio.h>

#include "../../common/types/layer5-7.h"
#include "../../common/define.h"
#include "../../common/printer_utils.h"

double ntp_fixed_to_seconds(uint32_t value);
void print_ntp(Ntp ntp);

#endif