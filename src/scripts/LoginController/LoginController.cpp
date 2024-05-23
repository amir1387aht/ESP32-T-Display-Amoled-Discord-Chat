#include <scripts/LoginController/LoginController.h>

WebServer server(WebServer_PORT);

IPAddress ip WebServer_IP;

void LoginController::start()
{
    ui_init();

    handleBotKeyPage();
}

void LoginController::update()
{
    server.handleClient();
}

void LoginController::handleBotKeyPage()
{
    WiFi.softAPConfig(ip, ip, IPAddress(255, 255, 255, 0));
    WiFi.softAP(WebServer_SSID, WebServer_PASSWORD);

    MDNS.begin(WebServer_DOMAIN_NAME);

    MDNS.addService("http", "tcp", WebServer_PORT);

    server.on("/", []()
    {
        server.send(200, "text/html", "<h1>You are connected</h1>");
    });

    server.begin();
}