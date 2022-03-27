#pragma once

#include "HttpHeadersCollection.h"
#include <string>
#include <vector>
#include <stdexcept>

class HttpRequest
{
public:

    HttpRequest(std::string_view method, std::string_view host, std::string_view path);
    HttpRequest(const HttpRequest&) = default;
    HttpRequest(HttpRequest&&) noexcept = default;
    HttpRequest& operator=(const HttpRequest&) = default;
    HttpRequest& operator=(HttpRequest&&) noexcept = default;

    void SetHostname(std::string_view hostname);
    void SetPath(std::string_view path);
    void SetMethod(std::string_view method);

    [[nodiscard]] std::string GetHostname() const;
    [[nodiscard]] std::string GetPath() const;
    [[nodiscard]] std::string GetMethod() const;
    void SetHeaders(HttpHeadersCollection headers);
    [[nodiscard]] const HttpHeadersCollection& GetHeaders() const;
    [[nodiscard]] HttpHeadersCollection& GetHeaders();
    void SetBody(std::string_view body);
    [[nodiscard]] std::string GetBody() const;

private:
    std::string _host;
    std::string _path;
    std::string _method;
    HttpHeadersCollection _headers;
    std::string _body;

    void CheckPath(std::string_view path) const;
};