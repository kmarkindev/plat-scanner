#include "HttpHeadersCollection.h"

auto HttpHeadersCollection::FindHeaderByName(std::string_view name) const
{
    return std::find_if(_headers.begin(), _headers.end(), [&name](auto h) {return h.second.GetName() == name;});
}

auto HttpHeadersCollection::FindHeaderByName(std::string_view name)
{
    return std::find_if(_headers.begin(), _headers.end(), [&name](auto h) {return h.second.GetName() == name;});
}

void HttpHeadersCollection::SetHeader(HttpHeader header)
{
    _headers.insert_or_assign(header.GetName(), std::move(header));
}

void HttpHeadersCollection::ClearHeaders()
{
    _headers.clear();
}

void HttpHeadersCollection::RemoveHeader(std::string_view name)
{
    auto iter = FindHeaderByName(name);

    if(iter != _headers.end())
        _headers.erase(iter);
}

const HttpHeader& HttpHeadersCollection::GetHeader(std::string_view name) const
{
    auto iter = FindHeaderByName(name);

    if(iter == _headers.end())
        throw std::runtime_error("Can't get header because it doesn't exist");

    return iter->second;
}

HttpHeader& HttpHeadersCollection::GetHeader(std::string_view name)
{
    return const_cast<HttpHeader&>(const_cast<const HttpHeadersCollection*>(this)->GetHeader(name));
}

bool HttpHeadersCollection::HasHeader(std::string_view name) const
{
    return FindHeaderByName(name) != _headers.end();
}

HttpHeadersCollection::Iterator HttpHeadersCollection::begin()
{
    return Iterator(_headers.begin());
}

HttpHeadersCollection::Iterator HttpHeadersCollection::end()
{
    return Iterator(_headers.end());
}

size_t HttpHeadersCollection::GetHeadersCount()
{
    return _headers.size();
}

HttpHeadersCollection::ConstIterator HttpHeadersCollection::cbegin() const
{
    return ConstIterator(_headers.cbegin());
}

HttpHeadersCollection::ConstIterator HttpHeadersCollection::cend() const
{
    return ConstIterator(_headers.cend());
}

HttpHeadersCollection::ConstIterator HttpHeadersCollection::begin() const
{
    return cbegin();
}

HttpHeadersCollection::ConstIterator HttpHeadersCollection::end() const
{
    return cend();
}
