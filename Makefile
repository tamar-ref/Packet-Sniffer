.PHONY: all main

all: main

main:
	gcc src/main.c \
		src/capture/sniffer.c \
		src/common/utils.c \
		src/printer/printer.c \
		src/printer/layer2.c \
		src/printer/payload.c \
		src/parser/layer2/ethernet.c \
		src/parser/layer2/vlan.c \
	    -o src/main