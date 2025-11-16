#pragma once

#include <SDL_render.h>
#include <SDL_video.h>
#include <functional>
#include <memory>

#include "SDLInitializer.h"
#include "./looper/Looper.h"
#include "Type.h"
#include "map_controller/MapController.h"

class Scene {
    public:
        Scene(SDLProvider* provider): sdlProvider(provider) {}

        SDL_Window* getWindow() const;
        SDL_Renderer* getRenderer() const;
        MapController& getMapController() const;
        void enterScene();
        void exitScene() const;

    private:
        SDLProvider* sdlProvider;
        std::unique_ptr<Looper> looper;
        std::unique_ptr<MapController> mapController;

        void freeResource() const;
        void handleSignal(unique_ptr<Signal> signal);
};