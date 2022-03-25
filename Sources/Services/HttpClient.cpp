#include "HttpClient.h"

HttpResponse HttpClient::Send(const HttpRequest& request)
{
    //https://wiki.wxwidgets.org/WxHTTP#Basic_Usage

    wxHTTP request;

    for(auto& header : headers)
        request.SetHeader(wxString::FromUTF8(header.name), wxString::FromUTF8(header.value));

    if(_timeout > -1)
        request.SetTimeout(static_cast<long>(_timeout));



    // this will wait until the user connects to the internet. It is important in case of dialup (or ADSL) connections
    while (!request.Connect(_T("www.google.com")))
        wxSleep(5);

    wxApp::IsMainLoopRunning();

    wxInputStream *httpStream = request.GetInputStream(_T("/intl/en/about.html"));

    if (request.GetError() == wxPROTO_NOERR)
    {
        wxString res;
        wxStringOutputStream out_stream(&res);
        httpStream->Read(out_stream);

        wxMessageBox(res);
        // wxLogVerbose( wxString(_T(" returned document length: ")) << res.Length() );
    }
    else
    {
        throw std::runtime_error("Failed to send request.");
    }

    wxDELETE(httpStream);
    request.Close();

    return HttpResponse();
}

void HttpClient::SetTimeout(int timeout)
{
    _timeout = timeout;
}

int HttpClient::GetTimeout() const
{
    return _timeout;
}
