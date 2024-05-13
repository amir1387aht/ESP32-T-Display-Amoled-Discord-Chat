// Scene.cpp

#include <corgi_framwork/Scene.h>

// Function to add scripts to the scene
void Scene::addScript(Script *script)
{
    if (scriptCount < MAX_SCRIPTS)
    {
        scripts[scriptCount] = script;

        scriptCount++;

        if (script->IsEnabled())
            script->start(); // Initialize the script
    }
}

// Function to update all scripts in the scene
void Scene::updateScripts()
{
    for (int i = 0; i < scriptCount; i++)
    {
        if (scripts[i]->IsEnabled())
        {
            scripts[i]->update(); // Update each script
        }
    }
}

// Virtual destructor to clean up scripts
Scene::~Scene()
{
    for (int i = 0; i < scriptCount; i++)
    {
        delete scripts[i]; // Delete each script
    }
}
