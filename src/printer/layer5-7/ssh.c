#include "../../../headers/printer/layer5-7/ssh.h"

void print_ssh(Ssh ssh)
{
    printf("\n%-*s: SSH\n",
           PRINT_LABEL_WIDTH,
           "Protocol");

    if (ssh.is_identification)
    {
        printf("%-*s: %s\n",
               PRINT_LABEL_WIDTH,
               "Identification",
               ssh.identification);
    }
    else
    {
        printf("%-*s: %u bytes\n",
               PRINT_LABEL_WIDTH,
               "Packet Length",
               ssh.packet_length);

        printf("%-*s: %u bytes\n",
               PRINT_LABEL_WIDTH,
               "Padding Length",
               ssh.padding_length);

        printf("%-*s: %u\n",
               PRINT_LABEL_WIDTH,
               "Message Type",
               ssh.message_type);

        printf("%-*s: %u bytes\n",
               PRINT_LABEL_WIDTH,
               "Payload Length",
               ssh.payload_length);

        printf("%-*s: ",
               PRINT_LABEL_WIDTH,
               "Payload");
        for (int i = 0; i < ssh.payload_length; i++)
        {
            printf("%02X ",
                   ssh.payload[i]);
        }
        printf("\n");

        printf("%-*s: ",
               PRINT_LABEL_WIDTH,
               "Padding");
        for (int i = 0; i < ssh.padding_length; i++)
        {
            printf("%02X ",
                   ssh.padding[i]);
        }
        printf("\n");
    }
}
