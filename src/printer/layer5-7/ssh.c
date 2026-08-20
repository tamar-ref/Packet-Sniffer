#include "../../../headers/printer/layer5-7/ssh.h"

void print_ssh(Ssh ssh)
{
       print_protocol_name("SSH");

       if (ssh.is_identification)
       {
              print_string_field("Identification", ssh.identification);
       }
       else
       {
              print_uint_bytes_field("Packet Length", ssh.packet_length);
              print_uint_bytes_field("Padding Length", ssh.padding_length);
              print_uint_field("Message Type", ssh.message_type);
              print_uint_bytes_field("Payload Length", ssh.payload_length);

              printf("%-*s: ",
                     PRINT_LABEL_WIDTH,
                     "Payload");
              for (int i = 0; i < ssh.payload_length; i++)
              {
                     printf("%02X ", ssh.payload[i]);
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
