//
// Created by ByteDance on 11/18/25.
//
#pragma once
#include "SDLInitializer.h"
#include "Scene.h"
#include "utils/Log.h"

#include <iostream>
#include <memory>

void startGame() {
    LOGD("---------------------");

    unique_ptr<SDLProvider> provider = make_unique<SDLProvider>();
    provider->init();

    unique_ptr<Scene> mainScene = make_unique<Scene>(provider.get());
    mainScene->enterScene();
}