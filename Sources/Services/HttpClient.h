#pragma once

#include <wx/wx.h>
#include <wx/protocol/http.h>
#include <wx/sstream.h>
#include <Models/HttpResponse.h>
#include <Models/HttpRequest.h>

class HttpClient
{
public:

    void SetTimeout(int timeout);
    [[nodiscard]] int GetTimeout() const;

    HttpResponse Send(const HttpRequest& request);

private:
    int _timeout;
};
