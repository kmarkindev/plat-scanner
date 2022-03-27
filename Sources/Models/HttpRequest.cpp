#include "HttpRequest.h"

void HttpRequest::SetHostname(std::string_view hostname)
{
    _host = hostname;
}

void HttpRequest::SetPath(std::string_view path)
{
    CheckPath(path);

    _path = path;
}

void HttpRequest::SetMethod(std::string_view method)
{
    _method = method;
}

std::string HttpRequest::GetHostname() const
{
    return _host;
}

std::string HttpRequest::GetPath() const
{
    return _path;
}

std::string HttpRequest::GetMethod() const
{
    return _method;
}

void HttpRequest::SetBody(std::string_view body)
{
    _body = body;
}

std::string HttpRequest::GetBody() const
{
    return _body;
}

void HttpRequest::SetHeaders(HttpHeadersCollection headers)
{
    _headers = std::move(headers);
}

const HttpHeadersCollection& HttpRequest::GetHeaders() const
{
    return _headers;
}

HttpRequest::HttpRequest(std::string_view method, std::string_view host, std::string_view path)
    : _method(method), _host(host), _path(path)
{
    CheckPath(path);
}

HttpHeadersCollection& HttpRequest::GetHeaders()
{
    return _headers;
}

void HttpRequest::CheckPath(std::string_view path) const
{
    if(path.empty() || !path.starts_with("/"))
        throw std::invalid_argument("Path can't be empty and must have '/' at the beginning");
}
