// app.cpp

#include "app.h"

void App::setup()
{
    setupDisplay();

    loadScene();

    amoled.setHomeButtonCallback([](void *ptr) {
        static uint32_t checkMs = 0;

        if (millis() > checkMs) 
            App::homeButtonPressed();

        checkMs = millis() + 200;
    }, NULL);
}

void App::setupDisplay()
{
    amoled.beginAMOLED_191();

    beginLvglHelper(amoled);
}

void App::loadScene()
{
    Scene *currentScene = new Scene("LoginScene");

    SceneManager::switchScene(currentScene);

    currentScene->addScript(new LoginController);
}

void App::homeButtonPressed()
{
    Scene *currentScene = new Scene("SettingScene");

    SceneManager::switchScene(currentScene);

    currentScene->addScript(new SettingController);
}

void App::update()
{
    lv_task_handler();
    delay(5);
}