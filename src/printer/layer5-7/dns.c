#include "../../../headers/printer/layer5-7/dns.h"

void print_dns_record(DnsRecord record, const char *record_type, int index)
{

       printf("%s %d\n", record_type, index);

       print_sub_string_field("Name", record.name);
       print_sub_hex_field("Type", record.type, 4);
       print_sub_hex_field("Class", record.class, 4);
       print_sub_uint_field("TTL", record.ttl);
       print_sub_uint_field("RDLENGTH", record.rdlength);

       printf("%-*s%-*s: ",
              SUB_LABEL_WIDTH,
              "",
              PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH,
              "RDATA");

       for (uint16_t i = 0; i < record.rdlength; i++)
       {
              printf("%02X ", record.rdata[i]);
       }
       printf("\n");
}

void print_dns(Dns dns)
{
       print_protocol_name("DNS");
       print_hex_field("Transaction ID", dns.transaction_id, 4);
       print_bits_field("Flags", dns.flags, DNS_FLAGS);
       print_hex_field("Questions", dns.questions, 4);
       print_hex_field("Answer Records", dns.answer_records, 4);
       print_hex_field("Athority Records", dns.authority_records, 4);
       print_hex_field("Additional Records", dns.additional_records, 4);

       for (uint16_t i = 0; i < dns.questions; i++)
       {
              printf("Question %u\n", i + 1);

              print_sub_string_field("Name", dns.dns_questions[i].name);
              print_sub_hex_field("Type", dns.dns_questions[i].type, 4);
              print_sub_hex_field("Class", dns.dns_questions[i].class, 4);
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
