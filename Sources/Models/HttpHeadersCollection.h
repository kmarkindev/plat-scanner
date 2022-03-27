#pragma once

#include <unordered_map>
#include <string>
#include <utility>
#include "HttpHeader.h"

class HttpHeadersCollection
{
public:

    struct Iterator
    {
    public:

        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = HttpHeader;
        using pointer           = value_type*;
        using reference         = value_type&;

        using internalPointer = std::unordered_map<std::string, HttpHeader>::iterator;

        Iterator(internalPointer ptr) : _ptr(std::move(ptr)) {}

        reference operator*() const { return _ptr->second; }
        pointer operator->() { return &_ptr->second; }

        Iterator& operator++() { _ptr++; return *this; }
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

        friend bool operator== (const Iterator& a, const Iterator& b) { return a._ptr == b._ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a._ptr != b._ptr; };

    private:
        internalPointer _ptr;
    };

    struct ConstIterator
    {
    public:

        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = const HttpHeader;
        using pointer           = value_type*;
        using reference         = value_type&;

        using internalPointer = std::unordered_map<std::string, HttpHeader>::const_iterator;

        ConstIterator(internalPointer ptr) : _ptr(std::move(ptr)) {}

        reference operator*() const { return _ptr->second; }
        pointer operator->() { return &_ptr->second; }

        ConstIterator& operator++() { _ptr++; return *this; }
        ConstIterator operator++(int) { ConstIterator tmp = *this; ++(*this); return tmp; }

        friend bool operator== (const ConstIterator& a, const ConstIterator& b) { return a._ptr == b._ptr; };
        friend bool operator!= (const ConstIterator& a, const ConstIterator& b) { return a._ptr != b._ptr; };

    private:
        internalPointer _ptr;
    };

    HttpHeadersCollection() = default;
    HttpHeadersCollection(const HttpHeadersCollection& other) = default;
    HttpHeadersCollection(HttpHeadersCollection&&) noexcept = default;
    HttpHeadersCollection& operator=(const HttpHeadersCollection&) = default;
    HttpHeadersCollection& operator=(HttpHeadersCollection&&) noexcept = default;

    void SetHeader(HttpHeader header);
    void ClearHeaders();
    void RemoveHeader(std::string_view name);
    [[nodiscard]] const HttpHeader& GetHeader(std::string_view name) const;
    [[nodiscard]] HttpHeader& GetHeader(std::string_view name);
    [[nodiscard]] bool HasHeader(std::string_view name) const;
    size_t GetHeadersCount();

    [[nodiscard]] Iterator begin();
    [[nodiscard]] Iterator end();
    [[nodiscard]] ConstIterator begin() const;
    [[nodiscard]] ConstIterator end() const;
    [[nodiscard]] ConstIterator cbegin() const;
    [[nodiscard]] ConstIterator cend() const;

private:
    std::unordered_map<std::string, HttpHeader> _headers;

    [[nodiscard]] auto FindHeaderByName(std::string_view name);
    [[nodiscard]] auto FindHeaderByName(std::string_view name) const;
};


