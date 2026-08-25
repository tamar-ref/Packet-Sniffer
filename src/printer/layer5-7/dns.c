#include "../../../headers/printer/layer5-7/dns.h"

void print_dns_record(DnsRecord record, const char *record_type, int index)
{

       printf("%s %d\n", record_type, index);

       print_string_field("Name", record.name, 1);
       print_hex_field("Type", record.type, 4, 1);
       print_hex_field("Class", record.class, 4, 1);
       print_uint_field("TTL", record.ttl, 1);
       print_uint_field("RDLENGTH", record.rdlength, 1);
       print_data("RDATA", record.rdlength, record.rdata, 1);
}

void print_dns(Dns dns)
{
       printf("\n");
       print_string_field("Protocol", "DNS", 0);
       print_hex_field("Transaction ID", dns.transaction_id, 4, 0);
       print_bits_field("Flags", dns.flags, DNS_FLAGS, 0);
       print_hex_field("Questions", dns.questions, 4, 0);
       print_hex_field("Answer Records", dns.answer_records, 4, 0);
       print_hex_field("Athority Records", dns.authority_records, 4, 0);
       print_hex_field("Additional Records", dns.additional_records, 4, 0);

       for (uint16_t i = 0; i < dns.questions; i++)
       {
              printf("Question %u\n", i + 1);

              print_string_field("Name", dns.dns_questions[i].name, 1);
              print_hex_field("Type", dns.dns_questions[i].type, 4, 1);
              print_hex_field("Class", dns.dns_questions[i].class, 4, 1);
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
