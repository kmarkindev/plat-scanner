#pragma once

#include <httplib/httplib.h>
#include <Models/HttpResponse.h>
#include <Models/HttpRequest.h>

class HttpClient
{
public:
    HttpResponse Send(const HttpRequest& request);
};
