#ifndef SETTING_CONTROLLER_H
#define SETTING_CONTROLLER_H

#include <corgi_framwork/Script.h>
#include <helpers/LV_Helper.h>
#include <ui/ui.h>
#include <app.h>
#include <Ticker.h>
#include <Arduino.h>

class SettingController : public Script
{
public:
    void start() override;
    void update() override;

    DEFINE_TYPE_TAG(SettingController)

    void WiFiTurnedOn();
    void WiFiTurnedOff();

    SettingController();
    ~SettingController();
    
private:
    void UpdateWiFiAPs();
    void UpdateWiFiSetting();

    lv_obj_t * ui_Setting_Left_Panel_WiFi_Panel_Container;

    Ticker WiFiUpdateTicker;
};

#endif