#ifndef TYPES_H
#define TYPES_H

#define MAX_PACKET_SIZE 65536

typedef struct
{
    int packet_number;
    unsigned char data[MAX_PACKET_SIZE];
    int length;

} Packet;

#endif