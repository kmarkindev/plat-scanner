#pragma once

#include <string>
#include <vector>
#include <stdexcept>

class HttpRequest
{
public:

    struct Header
    {
        Header() = default;

        Header& operator=(const HttpRequest::Header& other);
        Header& operator=(HttpRequest::Header&& other) noexcept;

        std::string name;
        std::string value;
    };

    void SetHostname(std::string_view hostname);
    void SetPath(std::string_view path);
    void SetMethod(std::string_view method);

    [[nodiscard]] std::string GetHostname() const;
    [[nodiscard]] std::string GetPath() const;
    [[nodiscard]] std::string GetMethod() const;

    void SetHeader(Header header);
    void ClearHeaders();
    void RemoveHeader(std::string_view name);
    [[nodiscard]] Header GetHeader(std::string_view name) const;
    [[nodiscard]] std::vector<Header> GetHeaders() const;
    [[nodiscard]] bool HasHeader(std::string_view name) const;

    void SetBody(std::string_view body);
    [[nodiscard]] std::string GetBody() const;

private:
    std::string _host;
    std::string _path;
    std::string _method;
    std::vector<Header> _headers;
    std::string _body;

    [[nodiscard]] auto FindHeaderByName(std::string_view name);
    [[nodiscard]] auto FindHeaderByName(std::string_view name) const;
};