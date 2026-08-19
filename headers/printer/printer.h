#ifndef PRINTER_H
#define PRINTER_H

#include <stdio.h>

#include "../common/types/packet.h"

#include "layer2/arp.h"
#include "layer2/ethernet.h"
#include "layer2/vlan.h"

#include "layer3/icmp.h"
#include "layer3/icmpv6.h"
#include "layer3/ipv4.h"
#include "layer3/ipv6.h"

#include "layer4/tcp.h"
#include "layer4/udp.h"

#include "layer5-7/dhcp.h"
#include "layer5-7/dns.h"
#include "layer5-7/ftp.h"
#include "layer5-7/http.h"
#include "layer5-7/https.h"
#include "layer5-7/ntp.h"
#include "layer5-7/ssh.h"
#include "layer5-7/telnet.h"

#include "payload.h"

void print_layer2(Packet packet);
void print_layer3(Packet packet);
void print_layer4(Packet packet);
void print_layer5_7(Packet packet);
void print_packet(Packet packet);

#endif