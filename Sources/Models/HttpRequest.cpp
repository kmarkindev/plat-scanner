#include "HttpRequest.h"

void ps::HttpRequest::SetHostname(std::string_view hostname)
{
    _host = hostname;
}

void ps::HttpRequest::SetPath(std::string_view path)
{
    CheckPath(path);

    _path = path;
}

void ps::HttpRequest::SetMethod(std::string_view method)
{
    _method = method;
}

std::string ps::HttpRequest::GetHostname() const
{
    return _host;
}

std::string ps::HttpRequest::GetPath() const
{
    return _path;
}

std::string ps::HttpRequest::GetMethod() const
{
    return _method;
}

void ps::HttpRequest::SetBody(std::string_view body)
{
    _body = body;
}

std::string ps::HttpRequest::GetBody() const
{
    return _body;
}

void ps::HttpRequest::SetHeaders(ps::HttpHeadersCollection headers)
{
    _headers = std::move(headers);
}

const ps::HttpHeadersCollection& ps::HttpRequest::GetHeaders() const
{
    return _headers;
}

ps::HttpRequest::HttpRequest(std::string_view method, std::string_view host, std::string_view path)
    : _method(method), _host(host), _path(path)
{
    CheckPath(path);
}

ps::HttpHeadersCollection& ps::HttpRequest::GetHeaders()
{
    return _headers;
}

void ps::HttpRequest::CheckPath(std::string_view path) const
{
    if(path.empty() || !path.starts_with("/"))
        throw std::invalid_argument("Path can't be empty and must have '/' at the beginning");
}
