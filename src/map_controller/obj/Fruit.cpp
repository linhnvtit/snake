//
// Created by ByteDance on 11/24/25.
//

#include "Fruit.h"

#include "../../utils/Utils.h"

void Fruit::spawn(int mapW, int mapH) {
    pos = {RANDOM_INT(0, mapW - 1), RANDOM_INT(0, mapH - 1)};
}

std::pair<int, int> Fruit::getPos() {
    return pos;
}