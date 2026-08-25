#include "../../../headers/printer/layer5-7/ssh.h"

void print_ssh(Ssh ssh)
{
       printf("\n");
       print_string_field("Protocol", "SSH", 0);

       if (ssh.is_identification)
       {
              print_string_field("Identification", ssh.identification, 0);
       }
       else
       {
              print_uint_bytes_field("Packet Length", ssh.packet_length, 0);
              print_uint_bytes_field("Padding Length", ssh.padding_length, 0);
              print_uint_field("Message Type", ssh.message_type, 0);
              print_uint_bytes_field("Payload Length", ssh.payload_length, 0);
              print_data("Payload", ssh.payload_length, ssh.payload, 0);
              print_data("Padding", ssh.padding_length, ssh.padding, 0);
       }
}
