#include "../../headers/capture/sniffer.h"

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
            packet.payload,
            MAX_PACKET_SIZE,
            0,
            NULL,
            NULL);

        if (packet.length < 0)
        {
            perror("Receive failed");
            continue;
        }

        size_t offset = 0;

        parse_packet(&packet, &offset);
        print_packet(packet);

        counter++;
    }

    close(socket_fd);
}