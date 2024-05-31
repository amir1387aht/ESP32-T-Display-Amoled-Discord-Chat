// Scene.h

#ifndef SCENE_H
#define SCENE_H

#include <corgi_framwork/Script.h>
#include <Arduino.h>

#define MAX_SCRIPTS 64 // Maximum number of scripts

class Scene
{
private:
    Script* scripts[MAX_SCRIPTS]; // Fixed-size array for scripts
    int scriptCount; // To keep track of the number of scripts
    String sceneName;

public:
    Scene(String name) : scriptCount(0), sceneName(name) {} // Initialize

    // Function to add scripts to the scene
    void addScript(Script *script);
    
    // Function to add scripts to the scene
    void removeScript(Script *script);

    // Function to update all scripts in the scene
    void updateScripts();

    // Virtual destructor to clean up scripts
    virtual ~Scene();
    

    String GetSceneName()
    {
        return sceneName;
    }
};

#endif // SCENE_H
