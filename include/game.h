#pragma once

#include "raylib.h"

class Game {
    public:
        Game();
        void draw();
        void update();
    private:
        bool running;
};