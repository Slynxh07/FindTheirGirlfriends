#pragma once

#include "raylib.h"
#include "player.h"

class Game {
    public:
        Game();
        void draw();
        void update(float dt);
    private:
        bool running;
        Player player;
};