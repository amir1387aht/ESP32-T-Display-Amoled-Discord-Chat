#include <scripts/SettingController/SettingController.h>

void SettingController::start()
{
    changeScreen(&ui_Setting_Screen, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_Setting_Screen_screen_init, false);
}

void SettingController::update()
{
}

SettingController::~SettingController()
{
    changeScreen(&lastScreen, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_Setting_Screen_screen_init);
}