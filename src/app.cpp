// app.cpp

#include "app.h"

bool App::IsInSetting = false;

void App::setup()
{
    Serial.begin(115200);

    SPIFFS_init();
    
    HTTP_helper::begin();

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
    if (!fileExists(KeyPath))
    {
        Scene *currentScene = new Scene("BotKeyScene");

        SceneManager::switchScene(currentScene);

        currentScene->addScript(new BotKeyController);
    }
    else
    {
        BotKeyController::onBotKeyEntered(readFile(KeyPath));
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
    App::IsInSetting = !App::IsInSetting;

    if (App::IsInSetting)
        SceneManager::currentScene->addScript(new SettingController);
    else
        SceneManager::currentScene->removeScriptByTypeName("SettingController");
}

void App::update()
{
    lv_task_handler();
    delay(5);
}