//
// Created by ByteDance on 11/16/25.
//

#ifndef SNAKE_MAPCONTROLLER_H
#define SNAKE_MAPCONTROLLER_H
#include <vector>
#include "../Type.h"
#include "obj/Background.h"
#include "obj/Fruit.h"
#include "obj/Snake.h"

using namespace std;

class MapController {
public:
    void initMap(int mapW, int mapH);
    Background* getBackgroundBitmap() const;
    Snake* getSnake() const;
    Fruit* getFruit() const;

    void gameOver();
    void updateMap();
    void onSnakeMove(SignalType signal) const;

private:
    unique_ptr<Background> background;
    unique_ptr<Snake> snake;
    unique_ptr<Fruit> fruit;

    int score;
    int mapW, mapH;

private:
    void checkSnakeState();
    void checkCollision();
    void logMapState();
};
#endif  // SNAKE_MAPCONTROLLER_H