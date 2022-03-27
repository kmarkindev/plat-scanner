#pragma once

#include <string>
#include <vector>
#include "HttpHeadersCollection.h"

class HttpResponse
{
public:

    HttpResponse(int code);
    HttpResponse(const HttpResponse&) = default;
    HttpResponse(HttpResponse&&) noexcept = default;
    HttpResponse& operator=(const HttpResponse&) = default;
    HttpResponse& operator=(HttpResponse&&) noexcept = default;

    [[nodiscard]] int GetCode() const;
    void SetCode(int code);
    [[nodiscard]] std::string GetBody() const;
    void SetBody(std::string_view body);
    [[nodiscard]] const HttpHeadersCollection& GetHeaders() const;
    [[nodiscard]] HttpHeadersCollection& GetHeaders();
    void SetHeaders(HttpHeadersCollection headers);

private:
    int _code;
    HttpHeadersCollection _headers;
    std::string _body;
};
