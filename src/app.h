// app.h

#ifndef APP_H
#define APP_H

#include <corgi_framwork/Scene.h>
#include <Arduino.h>
#include <corgi_framwork/SceneManager.h>
#include <lcd_helpers/LilyGo_AMOLED.h>
#include <lcd_helpers/LV_Helper.h>

#include <scripts/LoginController/LoginController.h>
#include <scripts/SettingController/SettingController.h>

class App
{
    public:
        void setup();
        void update();
        LilyGo_Class amoled;
        lv_obj_t *Keyboard;
        App() {}

    private:
        void setupDisplay();
        void loadScene();
        static void homeButtonPressed();
};

#endif // APP_H
