//
// Created by ByteDance on 11/16/25.
//

#ifndef SNAKE_BACKGROUND_H_H
#define SNAKE_BACKGROUND_H_H
#include <vector>

class Background {
public:
    void init();
    std::vector<int>& getBitMap();

private:
    std::vector<int> map;
};
#endif //SNAKE_BACKGROUND_H_H