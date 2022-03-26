#include "HttpClient.h"

HttpResponse HttpClient::Send(const HttpRequest& request)
{
    httplib::Client client(request.GetHostname());

    httplib::Request libRequest;

    libRequest.method = request.GetMethod();
    libRequest.path = request.GetPath();
    libRequest.body = request.GetBody();
    for(auto& header : request.GetHeaders())
        libRequest.headers.insert({header.GetName(), header.GetValue()});

    auto libResponse = client.send(libRequest);

    HttpResponse response(libResponse->status);
    response.SetBody(libResponse->body);
    HttpHeadersCollection headers;
    for(const auto& libHeader : libResponse->headers)
        headers.SetHeader(HttpHeader(libHeader.first, libHeader.second));
    response.SetHeaders(headers);

    return response;
}