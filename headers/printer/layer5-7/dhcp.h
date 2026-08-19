#ifndef DHCP_PRINTER_H
#define DHCP_PRINTER_H

#include <stdio.h>

#include "../../common/types/layer5-7.h"
#include "../../common/define.h"
#include "../../common/utils.h"

void print_dhcp_option(DhcpOption option, int index);
void print_dhcp(Dhcp dhcp);

#endif