#ifndef LAYER5_7_TYPE_H
#define LAYER5_7_TYPE_H

#include <stdint.h>

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

typedef struct
{
    uint8_t code;
    uint8_t length;
    uint8_t data[DHCP_OPTION_DATA_SIZE];

} DhcpOption;

typedef struct
{
    uint8_t op;
    uint8_t htype;
    uint8_t hlen;
    uint8_t hops;
    uint32_t xid;
    uint16_t secs;
    uint16_t flags;
    uint8_t ciaddr[IP_ADDRESS_SIZE];
    uint8_t yiaddr[IP_ADDRESS_SIZE];
    uint8_t siaddr[IP_ADDRESS_SIZE];
    uint8_t giaddr[IP_ADDRESS_SIZE];
    uint8_t chaddr[16];
    char sname[64];
    char file[128];
    uint32_t magic_cookie;
    DhcpOption options[MAX_DHCP_OPTIONS];
    int option_count;
} Dhcp;

typedef struct
{
    int is_request;
    int is_response;
    char command[FTP_COMMAND_SIZE];
    char argument[FTP_ARGUMENT_SIZE];
    int status_code;
    char status_text[FTP_STATUS_TEXT_SIZE];
} Ftp;

typedef struct
{
    char identification[SSH_IDENTIFICATION_SIZE];
    uint32_t packet_length;
    uint8_t padding_length;
    uint8_t message_type;
    uint8_t payload[MAX_SSH_PAYLOAD_SIZE];
    uint32_t payload_length;
    uint8_t padding[MAX_SSH_PAYLOAD_SIZE];
    int is_identification;
} Ssh;

typedef struct
{
    uint8_t li_version_mode;
    // li : 2
    // version : 3
    // mode : 3
    uint8_t stratum;
    uint8_t poll;
    uint8_t precision;
    uint32_t root_delay;
    uint32_t root_dispersion;
    uint8_t reference_id[4];
    uint64_t reference_timestamp;
    uint64_t originate_timestamp;
    uint64_t receive_timestamp;
    uint64_t transmit_timestamp;
} Ntp;

typedef struct
{

} Telnet;

#pragma pack(pop)

#endif