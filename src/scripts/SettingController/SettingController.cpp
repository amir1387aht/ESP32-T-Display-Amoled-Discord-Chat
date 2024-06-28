#include <scripts/SettingController/SettingController.h>

Ticker SettingController::WiFiUpdateTicker(UpdateWiFiAPs, 0, 1);

void SettingController::start()
{
    changeScreen(&ui_Setting_Screen, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_Setting_Screen_screen_init, false);

    UpdateWiFiSetting();
}

void SettingController::update()
{
    WiFiUpdateTicker.update();
}

SettingController::~SettingController()
{
    backToLastScreen();
}

SettingController::SettingController()
{
    backToLastScreen();
}

void SettingController::UpdateWiFiSetting()
{
    ui_Setting_Left_Panel_WiFi_Panel_Container = lv_list_create(ui_Setting_Left_Panel_WiFi_Panel);
    lv_obj_remove_style_all(ui_Setting_Left_Panel_WiFi_Panel_Container);
    lv_obj_set_height(ui_Setting_Left_Panel_WiFi_Panel_Container, 150);
    lv_obj_set_width(ui_Setting_Left_Panel_WiFi_Panel_Container, lv_pct(110));
    lv_obj_set_x(ui_Setting_Left_Panel_WiFi_Panel_Container, 0);
    lv_obj_set_y(ui_Setting_Left_Panel_WiFi_Panel_Container, 40);
    lv_obj_set_align(ui_Setting_Left_Panel_WiFi_Panel_Container, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Setting_Left_Panel_WiFi_Panel_Container,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);

    WiFiUpdateTicker.start();
}

void SettingController::UpdateWiFiAPs()
{
    Serial.println("Hello");
}

void SettingController::WiFiTurnedOn()
{
    _ui_flag_modify(ui_Setting_Left_Panel_WiFi_Panel_Container, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
}

void SettingController::WiFiTurnedOff()
{
    _ui_flag_modify(ui_Setting_Left_Panel_WiFi_Panel_Container, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}