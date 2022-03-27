#include "HttpClient.h"

HttpResponse HttpClient::Send(const HttpRequest& request)
{
    httplib::Client client(request.GetHostname());
    client.set_follow_location(true);
    client.enable_server_certificate_verification(false);

    httplib::Request libRequest;

    libRequest.method = request.GetMethod();
    libRequest.path = request.GetPath();
    libRequest.body = request.GetBody();
    for(auto& header : request.GetHeaders())
        libRequest.headers.insert({header.GetName(), header.GetValue()});

    auto libResponse = client.send(libRequest);

    auto error = libResponse.error();
    if(error != httplib::Error::Success)
        throw std::runtime_error("Can't send request. Error: " + httplib::to_string(error));

    HttpResponse response(libResponse->status);
    response.SetBody(libResponse->body);
    for(const auto& libHeader : libResponse->headers)
        response.GetHeaders().SetHeader(HttpHeader(libHeader.first, libHeader.second));

    return response;
}