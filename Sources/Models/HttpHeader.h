#pragma once

#include <string>
#include <stdexcept>

class HttpHeader
{
public:
    HttpHeader(std::string_view name, std::string_view value);
    HttpHeader(const HttpHeader&) = default;
    HttpHeader(HttpHeader&&) noexcept = default;
    HttpHeader& operator=(const HttpHeader&) = default;
    HttpHeader& operator=(HttpHeader&&) noexcept = default;

    [[nodiscard]] std::string GetName() const;
    void SetName(std::string_view name);
    [[nodiscard]] std::string GetValue() const;
    void SetValue(std::string_view value);

private:
    std::string _name;
    std::string _value;

    void CheckValue(std::string_view value);
};

