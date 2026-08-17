#include "../../headers/printer/layer4.h"

void print_tcp(Tcp tcp)
{
    printf("\n%-*s: TCP\n", PRINT_LABEL_WIDTH, "Protocol");

    printf("%-*s: %u\n", PRINT_LABEL_WIDTH, "Source Port", tcp.source_port);
    printf("%-*s: %u\n", PRINT_LABEL_WIDTH, "Destination Port", tcp.destination_port);
    printf("%-*s: 0x%08x\n", PRINT_LABEL_WIDTH, "Sequence Number", tcp.sequence_number);
    printf("%-*s: 0x%08x\n", PRINT_LABEL_WIDTH, "Acknowledgment Number", tcp.acknowledgment_number);

    uint16_t data_offset = (tcp.data_offset_reserved_flags >> 12) & 0x0F;
    uint16_t reserved = (tcp.data_offset_reserved_flags >> 9) & 0x07;
    uint16_t flags = tcp.data_offset_reserved_flags & 0x01FF;

    printf("%-*s: %u bytes\n", PRINT_LABEL_WIDTH, "Data Offset", data_offset * 4);

    printf("%-*s: ", PRINT_LABEL_WIDTH, "Reserved");
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

    printf("Flags\n");
    printf("%-*s%-*s: %d\n", SUB_LABEL_WIDTH, "", PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH, "CWR", cwr);
    printf("%-*s%-*s: %d\n", SUB_LABEL_WIDTH, "", PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH, "ECE", ece);
    printf("%-*s%-*s: %d\n", SUB_LABEL_WIDTH, "", PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH, "URG", urg);
    printf("%-*s%-*s: %d\n", SUB_LABEL_WIDTH, "", PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH, "ACK", ack);
    printf("%-*s%-*s: %d\n", SUB_LABEL_WIDTH, "", PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH, "PSH", psh);
    printf("%-*s%-*s: %d\n", SUB_LABEL_WIDTH, "", PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH, "RST", rst);
    printf("%-*s%-*s: %d\n", SUB_LABEL_WIDTH, "", PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH, "SYN", syn);
    printf("%-*s%-*s: %d\n", SUB_LABEL_WIDTH, "", PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH, "FIN", fin);

    printf("%-*s: 0x%04x\n", PRINT_LABEL_WIDTH, "Window Size", tcp.window_size);
    printf("%-*s: 0x%04x\n", PRINT_LABEL_WIDTH, "Checksum", tcp.checksum);
    printf("%-*s: 0x%04x\n", PRINT_LABEL_WIDTH, "Urgent Pointer", tcp.urgent_pointer);

    if (data_offset > 5)
    {
        int options_length = (data_offset - 5) * 4;

        char options_string[PRINT_LABEL_WIDTH];
        snprintf(options_string,
                 sizeof(options_string),
                 "Options (%d bytes)",
                 options_length);
        printf("%-*s: ", PRINT_LABEL_WIDTH, options_string);

        for (int i = 0; i < options_length; i++)
        {
            printf("%02X ", tcp.options[i]);
        }
        printf("\n");
    }
    else
    {
        printf("%-*s: None\n", PRINT_LABEL_WIDTH, "Options");
    }
}

void print_udp(Udp udp)
{
    printf("\n%-*s: UDP\n", PRINT_LABEL_WIDTH, "Protocol");

    printf("%-*s: %u\n", PRINT_LABEL_WIDTH, "Source Port", udp.source_port);
    printf("%-*s: %u\n", PRINT_LABEL_WIDTH, "Destination Port", udp.destination_port);
    printf("%-*s: %u\n", PRINT_LABEL_WIDTH, "Length", udp.length);
    printf("%-*s: 0x%04x\n", PRINT_LABEL_WIDTH, "Checksum", udp.checksum);
}

void print_layer4(Packet packet)
{
    printf("\nLayer 4\n");
    printf("-------------------------\n");

    if (packet.has_tcp)
    {
        print_tcp(packet.tcp);
    }
    else if (packet.has_udp)
    {
        print_udp(packet.udp);
    }
}