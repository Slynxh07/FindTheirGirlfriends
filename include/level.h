#pragma once

#include "raylib.h"
#include "npc.h"
#include <vector>

class Level {
    public:
        Level();
        Level(int id);
        Level(int id, const std::vector<NPC>& npcs);
        void draw();
        void update();
        int getID();
        const std::vector<Rectangle>& getGroundObjects() const;
    private:
        std::vector<Rectangle> groundObjects;
        std::vector<NPC> npcs;
        int id;
};