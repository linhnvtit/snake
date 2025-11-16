#pragma once

#include <SDL2/SDL.h>
#include <SDL_error.h>
#include <SDL_render.h>
#include <SDL_video.h>

#include "../utils/Log.h"

using namespace std;

class SDLProvider {
   private:
   public:
    SDL_Window* window;
    SDL_Renderer* renderer;

    void init() {
        if (SDL_Init(SDL_INIT_VIDEO)) {
            LOGE("SDL init failed, e: %s", SDL_GetError());
        }

        LOGD("SDL Loaded");

        window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);

        if (!window) {
            LOGE("Window cannot be initialized, e: %s", SDL_GetError());
            SDL_Quit();
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        if (!renderer) {
            LOGE("Renderer could not be created, e: %s", SDL_GetError());

            SDL_DestroyWindow(window);
            SDL_Quit();
        }

        LOGD("Initialization finish");
    }
};