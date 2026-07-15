.PHONY: all main

all: main

main:
	gcc src/main.c \
		src/capture/sniffer.c \
		src/common/utils.c \
		src/output/printer.c \
		src/parser/layer2/ethernet.c \
	    -o src/main