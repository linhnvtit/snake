//
// Created by ByteDance on 11/16/25.
//

#ifndef SNAKE_UTILS_H
#define SNAKE_UTILS_H

#include <chrono>

#define RANDOM_INT(min, max) ((std::rand() % ((max) - (min) + 1)) + (min))

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define NOW_MS() \
(std::chrono::duration_cast<std::chrono::milliseconds>( \
std::chrono::system_clock::now().time_since_epoch() \
).count())
#endif //SNAKE_UTILS_H