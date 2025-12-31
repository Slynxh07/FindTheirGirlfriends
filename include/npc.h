#pragma once

#include "raylib.h"
#include "animation.h"
#include "animationPlayer.h"
#include <string>

class NPC {
    public:
        NPC(std::string name, Rectangle hitBox, Animation walking, Animation idle);

    private:
        std::string name;
        Rectangle hitBox;
        AnimationPlayer animationplayer;
        Animation walking;
        Animation idle;
};