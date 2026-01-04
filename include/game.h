#pragma once

#include "raylib.h"
#include "player.h"
#include "level.h"
#include "npc.h"

class Game {
    public:
        Game();
        void draw();
        void update(float dt);
    private:
        bool running;
        Level currLevel;
        Player player;
        NPC john;
};