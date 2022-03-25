#include "HttpHeader.h"

HttpHeader::HttpHeader(std::string_view name, std::string_view value)
    : _name(name), _value(value)
{

}

std::string HttpHeader::GetName() const
{
    return _name;
}

void HttpHeader::SetName(std::string_view name)
{
    CheckValue(name);
    _name = name;
}

std::string HttpHeader::GetValue() const
{
    return _value;
}

void HttpHeader::SetValue(std::string_view value)
{
    CheckValue(value);
    _value = value;
}

void HttpHeader::CheckValue(std::string_view value)
{
    if(value.empty())
        throw std::invalid_argument("Header name or value cannot be empty");
}
