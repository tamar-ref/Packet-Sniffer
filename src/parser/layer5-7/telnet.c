#include "../../../headers/parser/layer5-7/telnet.h"

int is_telnet(Packet *packet, size_t *offset)
{
    if (packet == NULL || offset == NULL)
    {
        return 0;
    }

    if (*offset >= packet->length)
    {
        return 0;
    }

    for (size_t i = *offset; i < packet->length; i++)
    {
        if (packet->payload[i] != TELNET_IAC)
        {
            continue;
        }

        if (i + 1 >= packet->length)
        {
            return 0;
        }

        uint8_t command = packet->payload[i + 1];

        if (command >= TELNET_SE && command <= TELNET_IAC)
        {
            return 1;
        }
    }

    return 0;
}

int parse_telnet(Packet *packet, size_t *offset)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    if (is_telnet(packet, offset))
    {
        packet->has_telnet = 1;
        packet->telnet.data_length = 0;
        packet->telnet.command_count = 0;

        while (*offset < packet->length)
        {
            uint8_t byte = packet->payload[*offset];

            if (byte != TELNET_IAC)
            {
                if (packet->telnet.data_length < MAX_TELNET_DATA_SIZE)
                {
                    packet->telnet.data[packet->telnet.data_length++] = byte;
                }
                (*offset)++;
                continue;
            }

            uint8_t command = packet->payload[*offset + 1];

            if (command == TELNET_IAC)
            {
                if (packet->telnet.data_length < MAX_TELNET_DATA_SIZE)
                {
                    packet->telnet.data[packet->telnet.data_length++] = TELNET_IAC;
                }
                *offset += 2;
                continue;
            }

            if (command == TELNET_WILL ||
                command == TELNET_WONT ||
                command == TELNET_DO ||
                command == TELNET_DONT)
            {
                if (packet->telnet.command_count < MAX_TELNET_COMMANDS)
                {
                    TelnetCommand *telnet_command = &packet->telnet.commands[packet->telnet.command_count++];
                    telnet_command->command = command;
                    telnet_command->option = packet->payload[*offset + 2];
                    telnet_command->has_option = 1;
                }
                *offset += 3;
                continue;
            }

            if (command == TELNET_SB)
            {
                *offset += 2;
                while (*offset < packet->length)
                {
                    if (packet->payload[*offset] == TELNET_IAC)
                    {
                        if (*offset + 1 >= packet->length)
                        {
                            return -1;
                        }

                        if (packet->payload[*offset + 1] ==
                            TELNET_SE)
                        {
                            *offset += 2;
                            break;
                        }
                    }
                    (*offset)++;
                }
                continue;
            }

            if (command >= TELNET_SE && command <= TELNET_GA)
            {
                if (packet->telnet.command_count < MAX_TELNET_COMMANDS)
                {
                    TelnetCommand *telnet_command = &packet->telnet.commands[packet->telnet.command_count++];
                    telnet_command->command = command;
                    telnet_command->option = 0;
                    telnet_command->has_option = 0;
                }
                *offset += 2;
                continue;
            }

            return -1;
        }
    }

    return 0;
}