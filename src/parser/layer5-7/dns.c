#include "../../../headers/parser/layer5-7/dns.h"

int parse_dns_name(
    Packet *packet,
    size_t *offset,
    size_t dns_start,
    char *name,
    size_t name_size)
{
    if (packet == NULL ||
        offset == NULL ||
        name == NULL ||
        name_size == 0)
    {
        return -1;
    }

    size_t current_offset = *offset;
    size_t name_length = 0;
    int jumped = 0;

    while (1)
    {
        uint8_t label_length = packet->payload[current_offset];

        if ((label_length & 0xC0) == 0xC0)
        {
            uint16_t pointer =
                ((uint16_t)(label_length & 0x3F) << 8) |
                packet->payload[current_offset + 1];

            if (!jumped)
            {
                *offset = current_offset + 2;
                jumped = 1;
            }

            current_offset = dns_start + pointer;
            continue;
        }

        if (label_length == 0)
        {
            if (!jumped)
            {
                *offset = current_offset + 1;
            }

            break;
        }

        if (name_length != 0)
        {
            name[name_length++] = '.';
        }

        memcpy(
            name + name_length,
            packet->payload + current_offset + 1,
            label_length);

        name_length += label_length;
        current_offset += 1 + label_length;
    }

    name[name_length] = '\0';

    return 0;
}

int parse_dns_question(
    Packet *packet,
    size_t *offset,
    size_t dns_start,
    DnsQuestion *question)
{
    if (packet == NULL || offset == NULL || question == NULL)
    {
        return -1;
    }

    if (parse_dns_name(
            packet,
            offset,
            dns_start,
            question->name,
            sizeof(question->name)) != 0)
    {
        return -1;
    }

    memcpy(
        &question->type,
        packet->payload + *offset,
        sizeof(question->type));
    question->type = ntohs(question->type);
    *offset += sizeof(question->type);

    memcpy(
        &question->class,
        packet->payload + *offset,
        sizeof(question->class));
    question->class = ntohs(question->class);
    *offset += sizeof(question->class);

    return 0;
}

int parse_dns_record(
    Packet *packet,
    size_t *offset,
    size_t dns_start,
    DnsRecord *record)
{
    if (packet == NULL || offset == NULL || record == NULL)
    {
        return -1;
    }

    if (parse_dns_name(
            packet,
            offset,
            dns_start,
            record->name,
            sizeof(record->name)) != 0)
    {
        return -1;
    }

    memcpy(
        &record->type,
        packet->payload + *offset,
        sizeof(record->type));
    record->type = ntohs(record->type);
    *offset += sizeof(record->type);

    memcpy(
        &record->class,
        packet->payload + *offset,
        sizeof(record->class));
    record->class = ntohs(record->class);
    *offset += sizeof(record->class);

    memcpy(
        &record->ttl,
        packet->payload + *offset,
        sizeof(record->ttl));
    record->ttl = ntohl(record->ttl);
    *offset += sizeof(record->ttl);

    memcpy(
        &record->rdlength,
        packet->payload + *offset,
        sizeof(record->rdlength));
    record->rdlength = ntohs(record->rdlength);
    *offset += sizeof(record->rdlength);

    memcpy(
        record->rdata,
        packet->payload + *offset,
        record->rdlength);
    *offset += record->rdlength;

    return 0;
}

int parse_dns(Packet *packet, size_t *offset)
{
    if (packet == NULL || offset == NULL)
    {
        return -1;
    }

    packet->has_dns = 1;
    size_t dns_start = *offset;
    size_t basic_dns_size = sizeof(Dns) -
                            sizeof(packet->dns.dns_questions) -
                            sizeof(packet->dns.answers) -
                            sizeof(packet->dns.authorities) -
                            sizeof(packet->dns.additionals);

    memcpy(
        &packet->dns,
        packet->payload + *offset,
        basic_dns_size);

    packet->dns.transaction_id = ntohs(packet->dns.transaction_id);
    packet->dns.flags = ntohs(packet->dns.flags);
    packet->dns.questions = ntohs(packet->dns.questions);
    packet->dns.answer_records = ntohs(packet->dns.answer_records);
    packet->dns.authority_records = ntohs(packet->dns.authority_records);
    packet->dns.additional_records = ntohs(packet->dns.additional_records);

    *offset += basic_dns_size;

    for (uint16_t i = 0; i < packet->dns.questions; i++)
    {
        if (parse_dns_question(
                packet,
                offset,
                dns_start,
                &packet->dns.dns_questions[i]) != 0)
        {
            return -1;
        }
    }

    for (uint16_t i = 0; i < packet->dns.answer_records; i++)
    {
        if (parse_dns_record(
                packet,
                offset,
                dns_start,
                &packet->dns.answers[i]) != 0)
        {
            return -1;
        }
    }

    for (uint16_t i = 0; i < packet->dns.authority_records; i++)
    {
        if (parse_dns_record(
                packet,
                offset,
                dns_start,
                &packet->dns.authorities[i]) != 0)
        {
            return -1;
        }
    }

    for (uint16_t i = 0; i < packet->dns.additional_records; i++)
    {
        if (parse_dns_record(
                packet,
                offset,
                dns_start,
                &packet->dns.additionals[i]) != 0)
        {
            return -1;
        }
    }

    return 0;
}