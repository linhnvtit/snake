#include <SDL2/SDL.h>
#include <stdio.h>

#include <iostream>
#include <memory>

#include "./src/SDLInitializer.h"
#include "./src/Scene.h"
#include "utils/Log.h"

using namespace std;

int main() {
    LOGD("---------------------");

    unique_ptr<SDLProvider> provider = make_unique<SDLProvider>();
    provider->init();

    unique_ptr<Scene> mainScene = make_unique<Scene>(provider.get());
    mainScene->enterScene();

    return 0;
}