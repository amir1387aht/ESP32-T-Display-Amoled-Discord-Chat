// SceneManager.cpp

#include "corgi_framwork/SceneManager.h"
#include "app.h"

Scene *SceneManager::currentScene = nullptr;

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
    // Call setup function for App file
    App::setupScenes();
}

void SceneManager::loop()
{
    if (currentScene != nullptr)
    {
        currentScene->updateScripts(); // Update the current scene's scripts
    }
}