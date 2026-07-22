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

        if (parse_ethernet(&packet, &offset) != 0)
        {
            printf("Ethernet Error\n");
            continue;
        }

        print_packet(packet);

        counter++;
    }

    close(socket_fd);
}

// void start_sniffer()
// {
//     Packet packet;
//     unsigned char test_packet[] =
//         {
//             0x01,
//             0x02,
//             0x03,
//             0x04,
//             0x05,
//             0x06,
//             0x07,
//             0x08,
//             0x09,
//             0x10,
//             0x11,
//             0x12,
//             0x81,
//             0x00,
//             0xa0,
//             0x0a,
//             0x97,
//             0x96,
//             0x95,
//             0x094,
//         };

//     packet.length = sizeof(test_packet);

//     memcpy(packet.payload,
//            test_packet,
//            packet.length);

//     size_t offset = 0;

//     if (parse_ethernet(&packet, &offset) != 0)
//     {
//         printf("Ethernet Error\n");
//     }

//     print_packet(packet);
// }