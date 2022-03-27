#include "HttpResponse.h"

int HttpResponse::GetCode() const
{
    return _code;
}

void HttpResponse::SetCode(int code)
{
    _code = code;
}

std::string HttpResponse::GetBody() const
{
    return _body;
}

void HttpResponse::SetBody(std::string_view body)
{
    _body = body;
}

const HttpHeadersCollection& HttpResponse::GetHeaders() const
{
    return _headers;
}

void HttpResponse::SetHeaders(HttpHeadersCollection headers)
{
    _headers = std::move(headers);
}

HttpResponse::HttpResponse(int code)
    : _code(code)
{

}

HttpHeadersCollection& HttpResponse::GetHeaders()
{
    return _headers;
}
