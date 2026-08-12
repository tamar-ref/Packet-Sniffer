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

#endif