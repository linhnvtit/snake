//
// Created by ByteDance on 11/24/25.
//

#ifndef SNAKE_FRUIT_H
#define SNAKE_FRUIT_H
#include <utility>

class Fruit {
public:
    void spawn(int mapW, int mapH);
    std::pair<int, int> getPos();
private:
    std::pair<int, int> pos;
};
#endif //SNAKE_FRUIT_H