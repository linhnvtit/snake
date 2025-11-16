#pragma once

#include <iostream>
#include <unordered_map>

using namespace std;

class Object {};

enum class SignalType {
    TICK,

    QUIT,

    USER_ACTION_MOVE_LEFT,
    USER_ACTION_MOVE_RIGHT,
    USER_ACTION_MOVE_UP,
    USER_ACTION_MOVE_DOWN,
};

struct Signal {
    SignalType type;
    unordered_map<string, Object> extra;
};

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};
