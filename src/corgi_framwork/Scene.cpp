#include <corgi_framwork/Scene.h>

// Function to add scripts to the scene
void Scene::addScript(Script *script)
{
    scripts.push_back(script);
    if (script->IsEnabled())
        script->start(); // Initialize the script
}

// Function to remove scripts from the scene
void Scene::removeScript(Script *script)
{
    auto it = std::find(scripts.begin(), scripts.end(), script);
    if (it != scripts.end())
    {
        delete *it;        // Delete the script
        scripts.erase(it); // Remove the script from the vector
    }
}

// Function to remove scripts by type tag
void Scene::removeScriptByTypeName(const char *typeTag)
{
    auto it = std::remove_if(scripts.begin(), scripts.end(), [typeTag](Script *script)
    { return strcmp(script->getTypeTag(), typeTag) == 0; });

    if (it != scripts.end())
    {
        for (auto i = it; i != scripts.end(); ++i)
        {
            delete *i; // Delete the script
        }
        scripts.erase(it, scripts.end()); // Remove the scripts from the vector
    }
}

// Function to get a script by type name
Script* Scene::getScriptByTypeName(const char *typeTag)
{
    auto it = std::find_if(scripts.begin(), scripts.end(), [typeTag](Script *script)
    { return strcmp(script->getTypeTag(), typeTag) == 0; });

    if (it != scripts.end())
    {
        return *it; // Return the script if found
    }
    return nullptr; // Return nullptr if no script matches the type name
}

// Function to update all scripts in the scene
void Scene::updateScripts()
{
    for (auto script : scripts)
    {
        if (script->IsEnabled())
        {
            script->update(); // Update each script
        }
    }
}

// Virtual destructor to clean up scripts
Scene::~Scene()
{
    for (auto script : scripts)
    {
        delete script; // Delete each script
    }
}