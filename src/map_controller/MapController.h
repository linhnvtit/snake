//
// Created by ByteDance on 11/16/25.
//

#ifndef SNAKE_MAPCONTROLLER_H
#define SNAKE_MAPCONTROLLER_H
#include <vector>
#include "../Type.h"
#include "obj/Background.h"
#include "obj/Snake.h"

using namespace std;

class MapController {
public:
    void initMap();
    Background* getBackgroundBitmap() const;
    Snake* getSnake() const;

    void updateMap() const;
    void onSnakeMove(SignalType signal) const;

private:
    unique_ptr<Background> background;
    unique_ptr<Snake> snake;
};
#endif  // SNAKE_MAPCONTROLLER_H