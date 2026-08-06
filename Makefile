.PHONY: all main

all: main

main:
	gcc src/main.c \
		src/capture/sniffer.c \
		src/common/utils.c \
		src/printer/printer.c \
		src/printer/layer2.c \
		src/printer/layer3.c \
		src/printer/payload.c \
		src/parser/parser.c \
		src/parser/layer2/ethernet.c \
		src/parser/layer2/vlan.c \
		src/parser/layer2/arp.c \
		src/parser/layer3/ipv4.c \
		src/parser/layer3/ipv6.c \
	    -o src/main