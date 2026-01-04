#pragma once

#include "raylib.h"
#include "animation.h"
#include "animationPlayer.h"
#include <string>

class NPC {
    public:
        NPC();
        NPC(int id, std::string name, Rectangle hitbox, Vector2 pos, Vector2 velocity);
        NPC(int id, std::string name, Rectangle hitBox, Vector2 pos, Vector2 velocity, Animation walking, Animation idle);
        /*virtual*/ void draw();
        /*virtaul*/ void update();
        int getID();

    private:
        std::string name;
        Rectangle hitBox;
        AnimationPlayer animationplayer;
        Animation walking;
        Animation idle;
        Vector2 pos;
        Vector2 velocity;

        int id;
};