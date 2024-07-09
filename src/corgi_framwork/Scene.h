#ifndef SCENE_H
#define SCENE_H

#include <corgi_framwork/Script.h>
#include <Arduino.h>
#include <vector>
#include <algorithm>

class Scene
{
private:
    std::vector<Script *> scripts; // Vector for scripts
    String sceneName;

public:
    Scene(String name) : sceneName(name) {} // Initialize

    // Function to add scripts to the scene
    void addScript(Script *script);

    // Function to remove scripts from the scene
    void removeScript(Script *script);

    // Function to remove scripts by type tag
    void removeScriptByTypeName(const char *typeTag);

    // Function to get scripts by type tag
    Script* getScriptByTypeName(const char* typeTag);

    // Function to get scripts by type tag and type
    template <typename T>
    T* getScriptByType();

    // Function to update all scripts in the scene
    void updateScripts();

    // Virtual destructor to clean up scripts
    virtual ~Scene();

    String GetSceneName()
    {
        return sceneName;
    }
};

// Template function to get a script by type
template <typename T>
T* Scene::getScriptByType()
{
    for (auto script : scripts)
    {
        if (strcmp(script->getTypeTag(), T::TypeTag()) == 0)
        {
            return static_cast<T*>(script); // Use static_cast
        }
    }
    return nullptr; // Return nullptr if no script matches the type
}

#endif // SCENE_H