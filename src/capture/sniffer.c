#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netpacket/packet.h>
#include <net/ethernet.h>
#include <arpa/inet.h>

#include "../../headers/capture/sniffer.h"
#include "../../headers/output/printer.h"
#include "../../headers/common/types.h"

void start_sniffer()
{
    int socket_fd;

    socket_fd = socket(
        AF_PACKET,
        SOCK_RAW,
        htons(ETH_P_ALL));

    if (socket_fd < 0)
    {
        perror("Socket creation failed");
        exit(1);
    }

    printf("Sniffer started...\n");

    int counter = 1;

    while (1)
    {

        Packet packet;

        packet.packet_number = counter;

        packet.length = recvfrom(
            socket_fd,
            packet.data,
            MAX_PACKET_SIZE,
            0,
            NULL,
            NULL);

        if (packet.length < 0)
        {
            perror("Receive failed");
            continue;
        }

        print_packet(packet);

        counter++;
    }

    close(socket_fd);
}