#include "HTTP_helper.h"

void HTTP_helper::begin(const char *ssid, const char *password)
{
    connectWiFi(ssid, password);
}

void HTTP_helper::connectWiFi(const char *ssid, const char *password)
{
    WiFi.begin(ssid, password);

    Serial.print("Connecting to WiFi...");

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("Connected to WiFi");
}

void HTTP_helper::handleResponse(int httpResponseCode, const String &payload, ResponseCallback callback)
{
    if (callback)
    {
        callback(httpResponseCode, payload);
    }
    else
    {
        Serial.print("HTTP Response Code: ");
        Serial.println(httpResponseCode);
        Serial.println("Response Payload: ");
        Serial.println(payload);
    }
}

void HTTP_helper::addHeaders(HTTPClient &http, const std::vector<Header> &headers)
{
    for (const auto &header : headers)
    {
        http.addHeader(header.first, header.second);
    }
}

String HTTP_helper::getPayload(const std::vector<Payload> &payload)
{
    String result = "";
    JsonDocument doc;

    for (const auto &item : payload)
    {
        doc[item.first] = item.second;
    }

    serializeJson(doc, result);

    return result;
}

void HTTP_helper::get(String url, ResponseCallback callback, const std::vector<Header> &headers)
{
    HTTPClient http;

    http.begin(url);

    addHeaders(http, headers);

    int httpResponseCode = http.GET();

    String payload = "";

    if (httpResponseCode > 0)
    {
        payload = http.getString();
    }
    else
    {
        Serial.print("Error on GET request: ");
        Serial.println(httpResponseCode);
    }

    http.end();

    handleResponse(httpResponseCode, payload, callback);
}

void HTTP_helper::post(String url, ResponseCallback callback, const std::vector<Payload> &payload, const std::vector<Header> &headers, const char *contentType)
{
    HTTPClient http;

    http.begin(url);
    http.addHeader("Content-Type", contentType);

    addHeaders(http, headers);

    String PayloadString = getPayload(payload);

    int httpResponseCode = http.POST(PayloadString);

    String response = "";

    if (httpResponseCode > 0)
    {
        response = http.getString();
    }
    else
    {
        Serial.print("Error on POST request: ");
        Serial.println(httpResponseCode);
    }
    http.end();
    handleResponse(httpResponseCode, response, callback);
}

void HTTP_helper::put(String url, ResponseCallback callback, const std::vector<Payload> &payload, const std::vector<Header> &headers, const char *contentType)
{
    HTTPClient http;

    http.begin(url);
    http.addHeader("Content-Type", contentType);

    addHeaders(http, headers);

    String PayloadString = getPayload(payload);

    int httpResponseCode = http.PUT(PayloadString);

    String response = "";

    if (httpResponseCode > 0)
    {
        response = http.getString();
    }
    else
    {
        Serial.print("Error on PUT request: ");
        Serial.println(httpResponseCode);
    }
    http.end();
    handleResponse(httpResponseCode, response, callback);
}

void HTTP_helper::del(String url, ResponseCallback callback, const std::vector<Header> &headers)
{
    HTTPClient http;

    http.begin(url);

    addHeaders(http, headers);

    int httpResponseCode = http.sendRequest("DELETE");

    String response = "";

    if (httpResponseCode > 0)
    {
        response = http.getString();
    }
    else
    {
        Serial.print("Error on DELETE request: ");
        Serial.println(httpResponseCode);
    }
    
    http.end();

    handleResponse(httpResponseCode, response, callback);
}