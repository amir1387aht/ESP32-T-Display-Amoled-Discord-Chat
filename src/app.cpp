// This is main file for defining and adding scenes.
// only Setup function os enough for creating Scenes, you should put your app behavior on scripts folder.

#include "app.h"

void App::setupScenes()
{
    Scene *LoginScene = new Scene("LoginScene");

    SceneManager::switchScene(LoginScene);

    LoginScene->addScript(new LoginController());
}
