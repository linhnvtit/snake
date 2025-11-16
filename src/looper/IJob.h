#pragma once

#include <iostream>
#include <string>

#include "../Type.h"

class IJob {
   public:
    IJob(std::string tag) : TAG(tag) {
    }
    virtual std::unique_ptr<Signal> execute() = 0;

    virtual ~IJob() {};

    std::string TAG;
};