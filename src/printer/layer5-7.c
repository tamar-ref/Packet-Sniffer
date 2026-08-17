#include "../../headers/printer/layer5-7.h"

void print_http(Http http)
{
    printf("\n%-*s: HTTP\n", PRINT_LABEL_WIDTH, "Protocol");

    if (http.is_request)
    {
        printf("%-*s: %s\n", PRINT_LABEL_WIDTH, "Method", http.method);
        printf("%-*s: %s\n", PRINT_LABEL_WIDTH, "URI", http.uri);
        printf("%-*s: %s\n", PRINT_LABEL_WIDTH, "Version", http.version);
    }
    else if (http.is_response)
    {
        printf("%-*s: %s\n", PRINT_LABEL_WIDTH, "Version", http.version);
        printf("%-*s: %d\n", PRINT_LABEL_WIDTH, "Status Code", http.status_code);
        printf("%-*s: %s\n", PRINT_LABEL_WIDTH, "Status Text", http.status_text);
    }

    printf("Headers\n");

    for (int i = 0; i < http.header_count; i++)
    {
        printf("%-*s: %s\n", PRINT_LABEL_WIDTH, http.headers[i].name, http.headers[i].value);
    }
}

void print_https(Tls tls)
{
    printf("\n%-*s: HTTPS\n", PRINT_LABEL_WIDTH, "Protocol");

    printf("%-*s: 0x%02X", PRINT_LABEL_WIDTH, "Content Type", tls.content_type);
    switch (tls.content_type)
    {
    case 0x14:
        printf(" (Change Cipher Spec)\n");
        break;

    case 0x15:
        printf(" (Alert)\n");
        break;

    case 0x16:
        printf(" (Handshake)\n");
        break;

    case 0x17:
        printf(" (Application Data)\n");
        break;

    default:
        printf(" (Unknown)\n");
        break;
    }

    printf("%-*s: 0x%04X\n", PRINT_LABEL_WIDTH, "Version", tls.version);
    printf("%-*s: %u bytes\n", PRINT_LABEL_WIDTH, "Length", tls.length);
    
    printf("%-*s: ", PRINT_LABEL_WIDTH, "Fragment");
    for (int i = 0; i < tls.length; i++)
    {
        printf("%02X ", tls.fragment[i]);
    }
    printf("\n");
}

void print_dns_record(
    DnsRecord record,
    const char *record_type,
    int index)
{

    printf("%s %d\n", record_type, index);

    printf("%-*s%-*s: %s\n", SUB_LABEL_WIDTH, "", PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH, "Name", record.name);
    printf("%-*s%-*s: 0x%04x\n", SUB_LABEL_WIDTH, "", PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH, "Type", record.type);
    printf("%-*s%-*s: 0x%04x\n", SUB_LABEL_WIDTH, "", PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH, "Class", record.class);
    printf("%-*s%-*s: %u\n", SUB_LABEL_WIDTH, "", PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH, "TTL", record.ttl);
    printf("%-*s%-*s: %u\n", SUB_LABEL_WIDTH, "", PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH, "RDLENGTH", record.rdlength);

    printf("%-*s%-*s: ", SUB_LABEL_WIDTH, "", PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH, "RDATA");
    for (uint16_t i = 0; i < record.rdlength; i++)
    {
        printf("%02X ", record.rdata[i]);
    }
    printf("\n");
}

void print_dns(Dns dns)
{
    printf("\n%-*s: DNS\n", PRINT_LABEL_WIDTH, "Protocol");

    printf("%-*s: 0x%04x\n", PRINT_LABEL_WIDTH, "Transaction ID", dns.transaction_id);

    printf("%-*s: ", PRINT_LABEL_WIDTH, "Flags");
    print_bits(dns.flags, DNS_FLAGS);
    printf("\n");

    printf("%-*s: 0x%04x\n", PRINT_LABEL_WIDTH, "Questions", dns.questions);
    printf("%-*s: 0x%04x\n", PRINT_LABEL_WIDTH, "Answer Records", dns.answer_records);
    printf("%-*s: 0x%04x\n", PRINT_LABEL_WIDTH, "Athority Records", dns.authority_records);
    printf("%-*s: 0x%04x\n", PRINT_LABEL_WIDTH, "Additional Records", dns.additional_records);

    for (uint16_t i = 0; i < dns.questions; i++)
    {
        printf("Question %u\n", i + 1);
        printf("%-*s%-*s: %s\n", SUB_LABEL_WIDTH, "", PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH, "Name", dns.dns_questions[i].name);
        printf("%-*s%-*s: 0x%04x\n", SUB_LABEL_WIDTH, "", PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH, "Type", dns.dns_questions[i].type);
        printf("%-*s%-*s: 0x%04x\n", SUB_LABEL_WIDTH, "", PRINT_LABEL_WIDTH - SUB_LABEL_WIDTH, "Class", dns.dns_questions[i].class);
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

void print_layer5_7(Packet packet)
{
    printf("\nLayer 5-7\n");
    printf("-------------------------\n");

    if (packet.has_http)
    {
        print_http(packet.http);
    }
    if (packet.has_tls)
    {
        print_https(packet.tls);
    }
    if (packet.has_dns)
    {
        print_dns(packet.dns);
    }
}