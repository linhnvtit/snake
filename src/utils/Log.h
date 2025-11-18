#pragma once

#include <iostream>
#include <filesystem>
#include "Utils.h"
using namespace std;

#define LOGD(fmt, ...) \
do { \
    char buf[512]; \
    snprintf(buf, sizeof(buf), fmt, ##__VA_ARGS__); \
    std::cout << NOW_MS() << "|DEBUG|" << __FILENAME__  << "| " << buf << std::endl; \
} while(0)

#define LOGE(fmt, ...) \
do { \
    char buf[512]; \
    snprintf(buf, sizeof(buf), fmt, ##__VA_ARGS__); \
    std::cerr << NOW_MS() << "|ERROR|" << __FILENAME__  << "| " << buf << std::endl; \
} while(0)