#include "HttpResponse.h"

int ps::HttpResponse::GetCode() const
{
    return _code;
}

void ps::HttpResponse::SetCode(int code)
{
    _code = code;
}

std::string ps::HttpResponse::GetBody() const
{
    return _body;
}

void ps::HttpResponse::SetBody(std::string_view body)
{
    _body = body;
}

const ps::HttpHeadersCollection& ps::HttpResponse::GetHeaders() const
{
    return _headers;
}

void ps::HttpResponse::SetHeaders(ps::HttpHeadersCollection headers)
{
    _headers = std::move(headers);
}

ps::HttpResponse::HttpResponse(int code)
    : _code(code)
{

}

ps::HttpHeadersCollection& ps::HttpResponse::GetHeaders()
{
    return _headers;
}
