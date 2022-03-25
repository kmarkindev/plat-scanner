#include "HttpRequest.h"

auto HttpRequest::FindHeaderByName(std::string_view name)
{
    return std::find_if(_headers.begin(), _headers.end(), [&name](auto h) {return h.name == name;});
}

auto HttpRequest::FindHeaderByName(std::string_view name) const
{
    return std::find_if(_headers.begin(), _headers.end(), [&name](auto h) {return h.name == name;});
}

void HttpRequest::SetHostname(std::string_view hostname)
{
    _host = hostname;
}

void HttpRequest::SetPath(std::string_view path)
{
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

void HttpRequest::SetHeader(HttpRequest::Header header)
{
    auto iter = FindHeaderByName(header.name);

    if(iter == _headers.end())
        _headers.push_back(header);
    else
        std::swap(*iter, header);
}

void HttpRequest::ClearHeaders()
{
    _headers.clear();
}

void HttpRequest::RemoveHeader(std::string_view name)
{
    auto iter = FindHeaderByName(name);

    if(iter != _headers.end())
        _headers.erase(iter);
}

HttpRequest::Header HttpRequest::GetHeader(std::string_view name) const
{
    auto iter = FindHeaderByName(name);

    if(iter == _headers.end())
        throw std::runtime_error("Can't get header because it doesn't exist");

    return *iter;
}

std::vector<HttpRequest::Header> HttpRequest::GetHeaders() const
{
    return _headers;
}

bool HttpRequest::HasHeader(std::string_view name) const
{
    return FindHeaderByName(name) != _headers.end();
}

void HttpRequest::SetBody(std::string_view body)
{
    _body = body;
}

std::string HttpRequest::GetBody() const
{
    return _body;
}

HttpRequest::Header& HttpRequest::Header::operator=(const HttpRequest::Header& other)
{
    name = other.name;
    value = other.value;
    return *this;
}

HttpRequest::Header& HttpRequest::Header::operator=(HttpRequest::Header&& other)
{
    name = std::move(other.name);
    value = std::move(other.value);
    return *this;
}
