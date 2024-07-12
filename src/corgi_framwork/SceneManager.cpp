// SceneManager.cpp

#include "corgi_framwork/SceneManager.h"

Scene *SceneManager::currentScene = nullptr;
App *app = new App();

void SceneManager::switchScene(Scene *newScene)
{
    if (currentScene != nullptr)
    {
        delete currentScene; // Unload current scene and its scripts from memory
    }

    currentScene = newScene;
}

void SceneManager::setup()
{
    app->setup();
}

void SceneManager::loop()
{
    app->update();

    if (currentScene != nullptr)
        currentScene->updateScripts(); // Update the current scene's scripts
}