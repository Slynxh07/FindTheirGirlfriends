#pragma once

#include "raylib.h"
#include <vector>

class Level {
    public:
        Level();
        void draw();
        std::vector<Rectangle> getGroundObjects();
    private:
        std::vector<Rectangle> groundObjects;
};