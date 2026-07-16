
#include "../../headers/printer/ipv4.h"

void print_ipv4(IPv4 ipv4)
{
    struct in_addr source;
    struct in_addr destination;

    source.s_addr = ipv4.source_ip;
    destination.s_addr = ipv4.destination_ip;

    printf("\nLayer 3\n");
    printf("-----------------\n");

    printf("Protocol : IPv4\n\n");

    printf("Version : %d\n",
           ipv4.version);

    printf("Header Length : %d bytes\n",
           ipv4.header_length);

    printf("DSCP : %d\n",
           ipv4.dscp);

    printf("ECN : %d\n",
           ipv4.ecn);

    printf("Total Length : %d\n",
           ipv4.total_length);

    printf("Identification : %d\n",
           ipv4.identification);

    printf("Flags : %d\n",
           ipv4.flags);

    printf("Fragment Offset : %d\n",
           ipv4.fragment_offset);

    printf("TTL : %d\n",
           ipv4.ttl);

    printf("Protocol : %d\n",
           ipv4.protocol);

    printf("Header Checksum : 0x%04X\n",
           ipv4.header_checksum);

    printf("Source IP : %s\n",
           inet_ntoa(source));

    printf("Destination IP : %s\n",
           inet_ntoa(destination));

    if (ipv4.header_length > 20)
    {
        printf("Options : Exists\n");
    }
    else
    {
        printf("Options : None\n");
    }
}