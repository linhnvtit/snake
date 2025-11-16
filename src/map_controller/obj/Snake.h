//
// Created by ByteDance on 11/16/25.
//

#ifndef SNAKE_SNAKE_H_H
#define SNAKE_SNAKE_H_H
#include "../../Type.h"


class SnakeNode {
public:
    SnakeNode(pair<int, int> pos, SnakeNode* node): position(pos), next(node) {}

    pair<int, int> position;
    SnakeNode* next;
};

class Snake {
public:
    void init();
    void move();

    void changeDirection(Direction newDirection);
    void grow();

    SnakeNode* getHead() const;

private:
    static void dfs(SnakeNode* node);

    Direction direction = Direction::DOWN;
    SnakeNode* head = nullptr;

    float defaultSpeedInterval = 1000;
    float speedScale = 1.f;
    long lastMoveTime = 0;
    int moveCount = 0;

    unordered_map<Direction, pair<int, int>> dir = {
        {Direction::DOWN, {0, 1}},
        {Direction::UP, {0, -1}},
        {Direction::RIGHT, {1, 0}},
        {Direction::LEFT, {-1, 0}},
    };
};
#endif //SNAKE_SNAKE_H_H

