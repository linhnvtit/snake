//
// Created by ByteDance on 11/16/25.
//

#include "Background.h"

void Background::init(int mapW, int mapH) {
    // for now, mapW, mapH need to < 32 xD
    map = std::vector<int>(mapH, 0);
    // no need to generate wall
    // for (int i = 0; i < 32; ++i) {
    //     map[i] = 1 << i;
    // }
}


std::vector<int>& Background::getBitMap() {
    return map;
}
