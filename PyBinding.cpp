//
// Created by ByteDance on 11/18/25.
//

#include <pybind11/pybind11.h>
#include "src/Game.h"

namespace py = pybind11;

PYBIND11_MODULE(pySnake, m) {
    m.def("startGame", &startGame);
}
