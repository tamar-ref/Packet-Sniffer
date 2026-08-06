#include "../../headers/printer/layer4.h"

void print_tcp(Tcp tcp)
{
    printf("\nProtocol                : TCP\n");

    printf("Source Port             : %u\n", tcp.source_port);
    printf("Destination Port        : %u\n", tcp.destination_port);
    printf("Sequence Number         : 0x%08X\n", tcp.sequence_number);
    printf("Acknowledgment Number   : 0x%08X\n", tcp.acknowledgment_number);

    uint16_t data_offset = (tcp.data_offset_reserved_flags >> 12) & 0x0F;
    uint16_t reserved = (tcp.data_offset_reserved_flags >> 9) & 0x07;
    uint16_t flags = tcp.data_offset_reserved_flags & 0x01FF;

    printf("Data Offset             : %u bytes\n", data_offset * 4);
    printf("Reserved                : ");
    print_bits(reserved, RESERVED_BITS);
    printf("\n");

    uint8_t ns = (flags >> 8) & 1;
    uint8_t cwr = (flags >> 7) & 1;
    uint8_t ece = (flags >> 6) & 1;
    uint8_t urg = (flags >> 5) & 1;
    uint8_t ack = (flags >> 4) & 1;
    uint8_t psh = (flags >> 3) & 1;
    uint8_t rst = (flags >> 2) & 1;
    uint8_t syn = (flags >> 1) & 1;
    uint8_t fin = flags & 1;

    printf("Flags                   : ");
    printf("NS  %d\n", ns);
    printf("                          CWR %d\n", cwr);
    printf("                          ECE %d\n", ece);
    printf("                          URG %d\n", urg);
    printf("                          ACK %d\n", ack);
    printf("                          PSH %d\n", psh);
    printf("                          RST %d\n", rst);
    printf("                          SYN %d\n", syn);
    printf("                          FIN %d\n", fin);

    printf("Window Size             : 0x%04X\n", tcp.window_size);
    printf("Checksum                : 0x%04X\n", tcp.checksum);
    printf("Urgent Pointer          : 0x%04X\n", tcp.urgent_pointer);

    if (data_offset > 5)
    {
        int options_length = (data_offset - 5) * 4;
        if (options_length > 9)
        {
            printf("Options (%d bytes)      : ", options_length);
        }
        else
        {
            printf("Options (%d bytes)       : ", options_length);
        }
        for (int i = 0; i < options_length; i++)
        {
            printf("%02X ", tcp.options[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Options                 : None\n");
    }
}

void print_layer4(Packet packet)
{
    printf("\nLayer 4\n");
    printf("-------------------------\n");

    if (packet.has_tcp)
    {
        print_tcp(packet.tcp);
    }
}