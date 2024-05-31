#ifndef HTTP_HELPER_H
#define HTTP_HELPER_H

#include <WiFi.h>
#include <HTTPClient.h>
#include <functional>
#include <vector>
#include <utility>
#include <ArduinoJson.h>

class HTTP_helper
{
public:
    using ResponseCallback = std::function<void(int, const String &)>;
    using Header = std::pair<String, String>;
    using Payload = std::pair<String, String>;

    HTTP_helper() = delete; // Prevent instantiation
    ~HTTP_helper() = delete;

    static void begin(const char *ssid, const char *password);

    static void get(String url, ResponseCallback callback, const std::vector<Header> &headers = {});
    static void post(String url, ResponseCallback callback, const std::vector<Payload> &payload = {}, const std::vector<Header> &headers = {}, const char *contentType = "application/json");
    static void put(String url, ResponseCallback callback, const std::vector<Payload> &payload = {}, const std::vector<Header> &headers = {}, const char *contentType = "application/json");
    static void del(String url, ResponseCallback callback, const std::vector<Header> &headers = {});

private:
    static void connectWiFi(const char *ssid, const char *password);
    static void handleResponse(int httpResponseCode, const String &payload, ResponseCallback callback);
    static void addHeaders(HTTPClient &http, const std::vector<Header> &headers);
    static String getPayload(const std::vector<Payload> &payload);
};

#endif