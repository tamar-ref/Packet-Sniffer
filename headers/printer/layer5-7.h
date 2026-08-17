#ifndef LAYER_5_7_PRINTER_H
#define LAYER_5_7_PRINTER_H

#include <stdio.h>

#include "../common/define.h"
#include "../common/utils.h"
#include "../common/types/packet.h"
#include "../common/types/layer5-7.h"

void print_http(Http http);
void print_https(Tls tls);
void print_dns_record(DnsRecord record, const char *record_type, int index);
void print_dns(Dns dns);
void print_dhcp_option(DhcpOption option, int index);
void print_dhcp(Dhcp dhcp);
void print_layer5_7(Packet packet);

#endif