#ifndef SETTING_CONTROLLER_H
#define SETTING_CONTROLLER_H

#include <corgi_framwork/Script.h>
#include <helpers/LV_Helper.h>
#include <ui/ui.h>
#include <app.h>
#include <Ticker.h>
#include <Arduino.h>
#include <helpers/HTTP_helper.h>

class SettingController : public Script {
public:
    SettingController();
    ~SettingController();

    void start() override;
    void update() override;

    void WiFiTurnedOn();
    void WiFiTurnedOff();

    static SettingController* instance; // Static pointer to instance
    static void UpdateWiFiAPsWrapper(); // Static wrapper function

    DEFINE_TYPE_TAG(SettingController)

private:
    void UpdateWiFiAPs();
    void UpdateWiFiSetting();

    lv_obj_t * ui_Setting_Left_Panel_WiFi_Panel_Container;
    Ticker WiFiUpdateTicker;
};

#endif