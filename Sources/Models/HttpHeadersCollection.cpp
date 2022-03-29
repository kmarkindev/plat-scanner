#include "HttpHeadersCollection.h"

auto ps::HttpHeadersCollection::FindHeaderByName(std::string_view name) const
{
    return std::find_if(_headers.begin(), _headers.end(), [&name](auto h) {return h.second.GetName() == name;});
}

auto ps::HttpHeadersCollection::FindHeaderByName(std::string_view name)
{
    return std::find_if(_headers.begin(), _headers.end(), [&name](auto h) {return h.second.GetName() == name;});
}

void ps::HttpHeadersCollection::SetHeader(ps::HttpHeader header)
{
    _headers.insert_or_assign(header.GetName(), std::move(header));
}

void ps::HttpHeadersCollection::ClearHeaders()
{
    _headers.clear();
}

void ps::HttpHeadersCollection::RemoveHeader(std::string_view name)
{
    auto iter = FindHeaderByName(name);

    if(iter != _headers.end())
        _headers.erase(iter);
}

const ps::HttpHeader& ps::HttpHeadersCollection::GetHeader(std::string_view name) const
{
    auto iter = FindHeaderByName(name);

    if(iter == _headers.end())
        throw std::runtime_error("Can't get header because it doesn't exist");

    return iter->second;
}

ps::HttpHeader& ps::HttpHeadersCollection::GetHeader(std::string_view name)
{
    return const_cast<HttpHeader&>(const_cast<const HttpHeadersCollection*>(this)->GetHeader(name));
}

bool ps::HttpHeadersCollection::HasHeader(std::string_view name) const
{
    return FindHeaderByName(name) != _headers.end();
}

ps::HttpHeadersCollection::Iterator ps::HttpHeadersCollection::begin()
{
    return Iterator(_headers.begin());
}

ps::HttpHeadersCollection::Iterator ps::HttpHeadersCollection::end()
{
    return Iterator(_headers.end());
}

size_t ps::HttpHeadersCollection::GetHeadersCount()
{
    return _headers.size();
}

ps::HttpHeadersCollection::ConstIterator ps::HttpHeadersCollection::cbegin() const
{
    return ConstIterator(_headers.cbegin());
}

ps::HttpHeadersCollection::ConstIterator ps::HttpHeadersCollection::cend() const
{
    return ConstIterator(_headers.cend());
}

ps::HttpHeadersCollection::ConstIterator ps::HttpHeadersCollection::begin() const
{
    return cbegin();
}

ps::HttpHeadersCollection::ConstIterator ps::HttpHeadersCollection::end() const
{
    return cend();
}
