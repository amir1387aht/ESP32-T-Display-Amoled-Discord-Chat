// app.cpp

#include "app.h"

void App::setup()
{
    Serial.begin(115200);

    SPIFFS_init();

    HTTP_helper::begin(Station_SSID, Station_PASSWORD);

    setupDisplay();

    loadScene();

    amoled.setHomeButtonCallback([](void *ptr)
    {
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
    if (!fileExists("/bot/key.txt"))
    {
        Scene *currentScene = new Scene("BotKeyScene");

        SceneManager::switchScene(currentScene);

        currentScene->addScript(new BotKeyController);
    }
    else
    {
        BotKeyController::onBotKeyEntered(readFile("/bot/key.txt"));
    }
}

void App::onBotApplicationVerified()
{
    Scene *currentScene = new Scene("ChatScene");

    SceneManager::switchScene(currentScene);

    currentScene->addScript(new ChatController);
}

void App::homeButtonPressed()
{
    IsInSetting = !IsInSetting;

    if(IsInSetting)
        SceneManager::currentScene->addScript(new SettingController);
    else
        SceneManager::currentScene->
}

void App::update()
{
    lv_task_handler();
}