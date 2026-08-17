#ifndef LAYER5_7_TYPE_H
#define LAYER5_7_TYPE_H

#include "../define.h"

typedef struct
{
    char name[HTTP_HEADER_NAME_SIZE];
    char value[HTTP_HEADER_VALUE_SIZE];

} HttpHeader;

typedef struct
{
    int is_request;
    int is_response;
    char method[HTTP_METHOD_SIZE];
    char uri[HTTP_URI_SIZE];
    char version[HTTP_VERSION_SIZE];
    int status_code;
    char status_text[HTTP_STATUS_TEXT_SIZE];
    HttpHeader headers[MAX_HTTP_HEADERS];
    int header_count;
} Http;

#pragma pack(push, 1)

typedef struct
{
    uint8_t content_type;
    uint16_t version;
    uint16_t length;
    uint8_t fragment[MAX_TLS_FRAGMENT_SIZE];
} Tls;

typedef struct
{
    char name[DNS_NAME_SIZE];
    uint16_t type;
    uint16_t class;
} DnsQuestion;

typedef struct
{
    char name[DNS_NAME_SIZE];
    uint16_t type;
    uint16_t class;
    uint32_t ttl;
    uint16_t rdlength;
    uint8_t rdata[MAX_DNS_RDATA_SIZE];
} DnsRecord;

typedef struct
{
    uint16_t transaction_id;
    uint16_t flags;
    uint16_t questions;
    uint16_t answer_records;
    uint16_t authority_records;
    uint16_t additional_records;
    DnsQuestion dns_questions[MAX_DNS_QUESTIONS];
    DnsRecord answers[MAX_DNS_RECORDS];
    DnsRecord authorities[MAX_DNS_RECORDS];
    DnsRecord additionals[MAX_DNS_RECORDS];
} Dns;

#pragma pack(pop)

#endif