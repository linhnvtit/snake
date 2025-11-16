//
// Created by ByteDance on 11/16/25.
//

#include "Background.h"

void Background::init() {
    map = std::vector<int>(32);
    for (int i = 0; i < 32; ++i) {
        map[i] = 1 << i;
    }
}


std::vector<int>& Background::getBitMap() {
    return map;
}
