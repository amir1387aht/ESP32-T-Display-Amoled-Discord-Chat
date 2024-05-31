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

// Function to remove scripts from the scene
void Scene::removeScript(Script *script)
{
    for (int i = 0; i < scriptCount; i++)
    {
        if (scripts[i] == script)
        {
            delete scripts[i]; // Delete the script

            for (int j = i; j < scriptCount - 1; j++)
            {
                scripts[j] = scripts[j + 1]; // Shift remaining scripts
            }
            
            scripts[scriptCount - 1] = nullptr; // Nullify the last slot
            scriptCount--;
            break;
        }
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