// LoginController.h

#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include <corgi_framwork/Script.h>
#include <ui/ui.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ESPmDNS.h>
#include <web_pages/DiscordTokenPage.h>
#include <SPIFFS.h>
#include <ArduinoJson.h>
#include <urls.h>
#include <helpers/SPIFFS_helper.h>
#include <helpers/HTTP_helper.h>
#include <app.h>

class BotKeyController : public Script
{
public:
    void start() override;
    void update() override;
    static void onBotKeyEntered(String botKey);

    DEFINE_TYPE_TAG(BotKeyController)

private:
    void handleBotKeyPage();
    static void handleGetApplicationResponse(int httpResponseCode, const String &payload);
};

#endif