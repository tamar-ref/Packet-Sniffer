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

        if (parse_ethernet(packet.data,
                           packet.length,
                           &packet.ethernet) != 0)
        {
            printf("Invalid Ethernet Header\n");
            continue;
        }

        if (packet.ethernet.ether_type == 0x0800)
        {
            parse_ipv4(packet.data + 14,
                       packet.length - 14,
                       &packet.ipv4);
        }

        print_packet(packet);

        counter++;
    }

    close(socket_fd);
}