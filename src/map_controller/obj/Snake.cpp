//
// Created by ByteDance on 11/16/25.
//

#include "Snake.h"

#include <functional>

#include "../../utils/Utils.h"

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

vector<int> Snake::getBitMap() const {
    auto map = vector<int>(32, 0);
    dfsPost(head, [&](SnakeNode* node) {
        auto pos = node->position;
        map[pos.second] = 1 << pos.first;
    });

    return map;
}

void Snake::move() {
    if (NOW_MS() - lastMoveTime < (defaultSpeedInterval / speedScale)) return;
    moveCount += 1;

    dfsPost(head, [](SnakeNode* node) {
        if (node->next != nullptr)
            node->next->position = node->position;
    });
    head->position.first += dir[direction].first;
    head->position.second += dir[direction].second;

    lastMoveTime = NOW_MS();
}

void Snake::dfsPost(SnakeNode* node, function<void(SnakeNode*)> cb) {
    if (node == nullptr) return;
    dfsPost(node->next, cb);

    cb(node);
}