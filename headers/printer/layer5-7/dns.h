#ifndef DNS_PRINTER_H
#define DNS_PRINTER_H

#include <stdio.h>

#include "../../common/types/layer5-7.h"
#include "../../common/define.h"
#include "../../common/utils.h"

void print_dns_record(DnsRecord record, const char *record_type, int index);
void print_dns(Dns dns);

#endif