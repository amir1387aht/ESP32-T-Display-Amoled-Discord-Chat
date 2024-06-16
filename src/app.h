// app.h

#ifndef APP_H
#define APP_H

#include <corgi_framwork/Scene.h>
#include <corgi_framwork/SceneManager.h>

#include <Arduino.h>

#include <helpers/LilyGo_AMOLED.h>
#include <helpers/LV_Helper.h>
#include <helpers/SPIFFS_helper.h>

#include <scripts/BotKeyController/BotKeyController.h>
#include <scripts/SettingController/SettingController.h>
#include <scripts/ChatController/ChatController.h>

#include <config.h>

#include <ui/ui.h>

extern lv_obj_t *lastScreen;

class App
{
    public:
        App() {}
        LilyGo_Class amoled;

        void setup();
        void update();
        static void onBotApplicationVerified();
        static bool IsInSetting;

    private:
        void setupDisplay();
        void loadScene();
        static void homeButtonPressed();
};

#endif // APP_H
