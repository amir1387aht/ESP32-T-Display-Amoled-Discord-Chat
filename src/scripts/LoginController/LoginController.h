#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include <Arduino.h>
#include <config.h>

#include <corgi_framwork/Script.h>

#include <ui/ui.h>

#include <WiFi.h>
#include <WebServer.h>
#include <ESPmDNS.h>

class LoginController : public Script
{
public:
    void start() override;
    void update() override;

private:
    void handleBotKeyPage();
};

#endif