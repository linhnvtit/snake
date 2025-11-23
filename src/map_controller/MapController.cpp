//
// Created by ByteDance on 11/16/25.
//

#include "MapController.h"

#include "../Type.h"
#include "../utils/Log.h"
#include "obj/Snake.h"

void MapController::initMap(int mapW, int mapH) {
    LOGD("Start init");
    this->mapW = mapW;
    this->mapH = mapH;
    background = make_unique<Background>();
    snake = make_unique<Snake>();
    fruit = make_unique<Fruit>();
    score = 0;

    background->init(mapW, mapH);
    snake->init();
    fruit->spawn(mapW, mapH);

    LOGD("Finish init");
}

Background* MapController::getBackgroundBitmap() const {
    return background.get();
}

Snake* MapController::getSnake() const {
    return snake.get();
}

Fruit* MapController::getFruit() const {
    return fruit.get();
}

void MapController::gameOver() {
    LOGD("Game over, restarting...");

    score = 0;
    snake->init();
    fruit->spawn(mapW, mapH);
}

void MapController::updateMap() {
    checkSnakeState();
    checkCollision();

    snake->move();
}

void MapController::onSnakeMove(SignalType signal) const {
    switch (signal) {
        case SignalType::USER_ACTION_MOVE_UP:
            snake->changeDirection(Direction::UP);
            break;
        case SignalType::USER_ACTION_MOVE_DOWN:
            snake->changeDirection(Direction::DOWN);
            break;
        case SignalType::USER_ACTION_MOVE_LEFT:
            snake->changeDirection(Direction::LEFT);
            break;
        case SignalType::USER_ACTION_MOVE_RIGHT:
            snake->changeDirection(Direction::RIGHT);
            break;

        default:;
    }
}

void MapController::checkSnakeState() {
    Snake* snake = getSnake();
    SnakeNode* node = snake->getHead();
    auto map = vector<int>(32, 0);
    while (node) {
        if (
            (node->position.first < 0 || node->position.first >= mapW) ||
            (node->position.second < 0 || node->position.second >= mapH) ||
            (map[node->position.second] & (1 << node->position.first))
        ) {
            gameOver();
            break;
        };
        map[node->position.second] |= (1 << node->position.first);
        node = node->next;
    }
}

void MapController::checkCollision() {
    Fruit* fruit = getFruit();
    Snake* snake = getSnake();

    auto snakeBitMap = snake->getBitMap();
    auto isSnakeFoundFruit = false;

    while (1) {
        auto fruitPos = fruit->getPos();
        auto collide = snakeBitMap[fruitPos.second] & (1 << fruitPos.first);

        if (collide) {
            fruit->spawn(mapW, mapH);

            if (!isSnakeFoundFruit) {
                isSnakeFoundFruit = true;
                score++;
            }
        } else break;
    }

    if (isSnakeFoundFruit) {
        LOGD("Snake just ate a fruit");
        snake->grow();
    }
}

void MapController::logMapState() {
    // log map state into a file
    // can follow this format: [Snake map] [Fruits map]
    // normally [Snake map], [Fruits map] will be an vector<int>(32)
    // then can try making a reply off of that log
}