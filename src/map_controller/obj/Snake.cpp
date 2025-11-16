//
// Created by ByteDance on 11/16/25.
//

#include "Snake.h"

#include "../../../utils/Utils.h"

void Snake::init() {
    direction = Direction::DOWN;
    head = new SnakeNode(
        { RANDOM_INT(10,20), RANDOM_INT(10,20) },
        nullptr
    );
}

void Snake::changeDirection(Direction newDirection) {
    direction = newDirection;
}

void Snake::grow() {
    pair<int, int> newPos = head->position;
    newPos.first += dir[direction].first;
    newPos.second += dir[direction].second;

    SnakeNode* newHead = new SnakeNode(newPos, head);
    head = newHead;
}

SnakeNode* Snake::getHead() const {
    return head;
}

void Snake::move() {
    if (NOW_MS() - lastMoveTime < (defaultSpeedInterval / speedScale)) return;
    moveCount += 1;

    dfs(head);
    head->position.first += dir[direction].first;
    head->position.second += dir[direction].second;

    lastMoveTime = NOW_MS();
    if (!(moveCount % 3)) grow();
}

void Snake::dfs(SnakeNode* node) {
    if (node == nullptr) return;
    dfs(node->next);

    if (node->next != nullptr)
        node->next->position = node->position;
}