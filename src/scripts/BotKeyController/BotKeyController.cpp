// BotKeyController.cpp

#include <scripts/BotKeyController/BotKeyController.h>

AsyncWebServer server(80);

IPAddress ip WebServer_IP;

void BotKeyController::start()
{
    ui_init();

    handleBotKeyPage();
}

void BotKeyController::update()
{
}

void BotKeyController::handleBotKeyPage()
{
    WiFi.softAPConfig(ip, ip, IPAddress(255, 255, 255, 0));
    WiFi.softAP(WebServer_SSID, WebServer_PASSWORD);

    MDNS.begin(WebServer_DOMAIN_NAME);

    MDNS.addService("http", "tcp", WebServer_PORT);

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
    { request->send(200, "text/html", DiscordTokenPageHtmlContent); });

    server.on("/form-bot-key-get", HTTP_GET, [](AsyncWebServerRequest *request)
    {
        String keyContent = readFile(KeyPath);

        keyContent.replace("Bot ", "");

        JsonDocument doc;

        doc["bot_key"] = keyContent;

        serializeJson(doc, keyContent);

        request->send(200, "text/json", keyContent); 
    });

    server.on("/form-bot-key-set", HTTP_POST, [](AsyncWebServerRequest *request)
    {
        if (request->hasParam("bot-key", true))
        {
            String botKey = request->getParam("bot-key", true)->value();

            botKey = "Bot " + botKey;

            writeFile(KeyPath, botKey.c_str());

            request->send(200, "text/plain", "Bot key saved successfully");

            BotKeyController::onBotKeyEntered(botKey);
        }
        else
        {
            request->send(400, "text/plain", "No bot key found in the request");
        } 
    });

    server.begin();
}

void BotKeyController::onBotKeyEntered(String botKey)
{
    lv_obj_clear_flag(ui_GettingInfoPanel, LV_OBJ_FLAG_HIDDEN);

    std::vector<HTTP_helper::Header> headers = {
        {"Authorization", botKey}
    };

    HTTP_helper::get(Urls_Manager::GetBotApplicationUrl(), handleGetApplicationResponse, headers);
}

void BotKeyController::handleGetApplicationResponse(int httpResponseCode, const String &payload)
{
    lv_obj_add_flag(ui_GettingInfoPanel, LV_OBJ_FLAG_HIDDEN);

    if (httpResponseCode == 200)
    {
        writeFile(ApplicationPath, payload);

        if(server && MDNS)
        {
            server.end();
            MDNS.end();
        }

        App::onBotApplicationVerified();
    }
    else
    {
        lv_msgbox_create(NULL, (String("Error", "Unable To Verify Bot Key, Try Set Key Again, Code : ") + httpResponseCode).c_str(), NULL, true);
    }
}