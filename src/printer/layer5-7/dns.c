#include "../../../headers/printer/layer5-7/dns.h"

void print_dns_record(DnsRecord record, const char *record_type, int index)
{

    printf("%s %d\n",
           record_type, index);

    printf("%-*s%-*s: %s\n",
           SUB_LABEL_WIDTH,
           "",
           PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH,
           "Name",
           record.name);

    printf("%-*s%-*s: 0x%04x\n",
           SUB_LABEL_WIDTH,
           "",
           PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH,
           "Type",
           record.type);

    printf("%-*s%-*s: 0x%04x\n",
           SUB_LABEL_WIDTH,
           "",
           PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH,
           "Class",
           record.class);

    printf("%-*s%-*s: %u\n",
           SUB_LABEL_WIDTH,
           "",
           PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH,
           "TTL",
           record.ttl);

    printf("%-*s%-*s: %u\n",
           SUB_LABEL_WIDTH,
           "",
           PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH,
           "RDLENGTH",
           record.rdlength);

    printf("%-*s%-*s: ",
           SUB_LABEL_WIDTH,
           "",
           PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH,
           "RDATA");

    for (uint16_t i = 0; i < record.rdlength; i++)
    {
        printf("%02X ",
               record.rdata[i]);
    }
    printf("\n");
}

void print_dns(Dns dns)
{
    printf("\n%-*s: DNS\n",
           PRINT_LABEL_WIDTH,
           "Protocol");

    printf("%-*s: 0x%04x\n",
           PRINT_LABEL_WIDTH,
           "Transaction ID",
           dns.transaction_id);

    printf("%-*s: ",
           PRINT_LABEL_WIDTH,
           "Flags");
    print_bits(dns.flags,
               DNS_FLAGS);
    printf("\n");

    printf("%-*s: 0x%04x\n",
           PRINT_LABEL_WIDTH,
           "Questions",
           dns.questions);

    printf("%-*s: 0x%04x\n",
           PRINT_LABEL_WIDTH,
           "Answer Records",
           dns.answer_records);

    printf("%-*s: 0x%04x\n",
           PRINT_LABEL_WIDTH,
           "Athority Records",
           dns.authority_records);

    printf("%-*s: 0x%04x\n",
           PRINT_LABEL_WIDTH,
           "Additional Records",
           dns.additional_records);

    for (uint16_t i = 0; i < dns.questions; i++)
    {
        printf("Question %u\n",
               i + 1);

        printf("%-*s%-*s: %s\n",
               SUB_LABEL_WIDTH,
               "",
               PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH,
               "Name",
               dns.dns_questions[i].name);

        printf("%-*s%-*s: 0x%04x\n",
               SUB_LABEL_WIDTH,
               "",
               PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH,
               "Type",
               dns.dns_questions[i].type);

        printf("%-*s%-*s: 0x%04x\n",
               SUB_LABEL_WIDTH,
               "",
               PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH,
               "Class",
               dns.dns_questions[i].class);
    }

    for (uint16_t i = 0; i < dns.answer_records; i++)
    {
        print_dns_record(dns.answers[i], "Answer", i + 1);
    }

    for (uint16_t i = 0; i < dns.authority_records; i++)
    {
        print_dns_record(dns.authorities[i], "Authority", i + 1);
    }

    for (uint16_t i = 0; i < dns.additional_records; i++)
    {
        print_dns_record(dns.additionals[i], "Additional", i + 1);
    }
}
