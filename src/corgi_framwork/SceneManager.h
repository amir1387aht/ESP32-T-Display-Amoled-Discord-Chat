// SceneManager.h

#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <corgi_framwork/Scene.h>

class SceneManager
{
    public:
        static Scene *currentScene;

        static void switchScene(Scene *newScene);
        static void setup();
        static void loop();
};

#endif // SCENE_MANAGER_H