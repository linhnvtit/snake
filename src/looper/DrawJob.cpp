#include "DrawJob.h"

#include "../map_controller/obj/Snake.h"


constexpr int SIZE = 40;

unique_ptr<Signal> DrawJob::execute() {
    SDL_Renderer* renderer = scene.getRenderer();

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    drawBackground(renderer);
    drawSnake(renderer);
    drawFruit(renderer);

    SDL_RenderPresent(renderer);

    return make_unique<Signal>(Signal{SignalType::TICK, {}});
}

void DrawJob::drawBackground(SDL_Renderer* renderer) {
    Background* background = scene.getMapController().getBackgroundBitmap();
    vector<int> map = background->getBitMap();
    int width = map.size(), height = map.size();

    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            if (map[j] & (1 << i)) {
                drawBlock(renderer, i, j, true, 255, 0, 0);
            } else {
                drawBlock(renderer, i, j, false, 255, 255, 0);
            }
        }
    }
}

void DrawJob::drawSnake(SDL_Renderer* renderer) {
    Snake* snake = scene.getMapController().getSnake();

    SnakeNode* node = snake->getHead();
    while (node != nullptr) {
        drawBlock(renderer, node->position.first, node->position.second, true, 0, 255, 0);
        node = node->next;
    }
}

void DrawJob::drawFruit(SDL_Renderer* renderer) {
    Fruit* fruit = scene.getMapController().getFruit();
    pair<int, int> pos = fruit->getPos();
    drawBlock(renderer, pos.first, pos.second, true, 0, 0, 255);
}


void DrawJob::drawBlock(SDL_Renderer* renderer, int i, int j, bool shouldFill, int8_t r, int8_t g, int8_t b) {
    SDL_Rect rect = { 100 + SIZE * i, 100 + SIZE * j, SIZE, SIZE};
    if (shouldFill) {
        SDL_SetRenderDrawColor(renderer, r, g, b, 255);
        SDL_RenderFillRect(renderer, &rect);
    } else {
        SDL_SetRenderDrawColor(renderer, r, g, b, 255);
        SDL_RenderDrawRect(renderer, &rect);
    }
}