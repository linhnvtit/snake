#pragma once

#include <SDL_render.h>

#include <memory>
#include <string>

#include "../Scene.h"
#include "IJob.h"

using namespace std;

class DrawJob : public IJob {
public:
    DrawJob(Scene& scene, std::string tag) : IJob(tag), scene(scene) {
    }

    unique_ptr<Signal> execute();

private:
    Scene& scene;

    void drawBackground(SDL_Renderer* renderer);
    void drawSnake(SDL_Renderer* renderer);
    void drawFruit(SDL_Renderer* renderer);

    static void drawBlock(SDL_Renderer* renderer,int i, int j, bool shouldFill, int8_t r, int8_t g, int8_t b);
};