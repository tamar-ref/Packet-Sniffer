#ifndef PARSER_H
#define PARSER_H

#include <arpa/inet.h>

#include "../common/types/packet.h"
#include "../common/define.h"
#include "./layer2/ethernet.h"
#include "./layer2/arp.h"
#include "./layer2/vlan.h"
#include "./layer3/ipv4.h"
#include "./layer3/ipv6.h"
#include "./layer3/icmp.h"
#include "./layer3/icmpv6.h"
#include "./layer4/tcp.h"
#include "./layer4/udp.h"

#include "./layer5-7/http.h"
#include "./layer5-7/https.h"
#include "./layer5-7/dns.h"
#include "./layer5-7/dhcp.h"
#include "./layer5-7/ftp.h"
#include "./layer5-7/ssh.h"
#include "./layer5-7/ntp.h"
#include "./layer5-7/telnet.h"

int parse_layer2(Packet *packet, size_t *offset, uint16_t *next_protocol);
int parse_layer3(Packet *packet, size_t *offset, uint16_t *next_protocol);
int parse_layer4(Packet *packet, size_t *offset, uint16_t *next_protocol);
int parse_layer5_7(Packet *packet, size_t *offset);
void parse_packet(Packet *packet, size_t *offset);

#endif