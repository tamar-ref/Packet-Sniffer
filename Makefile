.PHONY: all main

all: main

main:
	gcc src/main.c \
		src/capture/sniffer.c \
		src/common/utils.c \
		src/common/printer_utils.c \
		src/printer/printer.c \
		src/printer/payload.c \
		src/printer/layer2/ethernet.c \
		src/printer/layer2/vlan.c \
		src/printer/layer2/arp.c \
		src/printer/layer3/ipv4.c \
		src/printer/layer3/ipv6.c \
		src/printer/layer3/icmp.c \
		src/printer/layer3/icmpv6.c \
		src/printer/layer4/tcp.c \
		src/printer/layer4/udp.c \
		src/printer/layer5-7/dhcp.c \
		src/printer/layer5-7/dns.c \
		src/printer/layer5-7/ftp.c \
		src/printer/layer5-7/http.c \
		src/printer/layer5-7/https.c \
		src/printer/layer5-7/ntp.c \
		src/printer/layer5-7/ssh.c \
		src/printer/layer5-7/telnet.c \
		src/parser/parser.c \
		src/parser/layer2/ethernet.c \
		src/parser/layer2/vlan.c \
		src/parser/layer2/arp.c \
		src/parser/layer3/ipv4.c \
		src/parser/layer3/ipv6.c \
		src/parser/layer3/icmp.c \
		src/parser/layer3/icmpv6.c \
		src/parser/layer4/tcp.c \
		src/parser/layer4/udp.c \
		src/parser/layer5-7/dhcp.c \
		src/parser/layer5-7/dns.c \
		src/parser/layer5-7/ftp.c \
		src/parser/layer5-7/http.c \
		src/parser/layer5-7/https.c \
		src/parser/layer5-7/ntp.c \
		src/parser/layer5-7/ssh.c \
		src/parser/layer5-7/telnet.c \
	    -o src/main