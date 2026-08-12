#ifndef LAYER5_7_TYPE_H
#define LAYER5_7_TYPE_H

#define MAX_HTTP_HEADERS 50

#define HTTP_METHOD_SIZE 16
#define HTTP_URI_SIZE 1024
#define HTTP_VERSION_SIZE 16
#define HTTP_STATUS_TEXT_SIZE 128

#define HTTP_HEADER_NAME_SIZE 128
#define HTTP_HEADER_VALUE_SIZE 1024

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

#endif