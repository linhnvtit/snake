//
// Created by ByteDance on 11/16/25.
//

#include "MapController.h"

#include "../Type.h"
#include "../utils/Log.h"
#include "obj/Snake.h"

void MapController::initMap() {
    LOGD("Start init");
    background = make_unique<Background>();
    snake = make_unique<Snake>();

    background->init();
    snake->init();
    LOGD("Finish init");
}

Background* MapController::getBackgroundBitmap() const {
    return background.get();
}

Snake* MapController::getSnake() const {
    return snake.get();
}

void MapController::updateMap() const {
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