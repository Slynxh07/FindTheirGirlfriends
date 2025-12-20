#pragma once

#include "raylib.h"
#include "animation.h"
#include "animationPlayer.h"

class Player {
    public:
        Player();
        void draw();
        void update(float dt);

    private:
        Vector2 pos;
        Vector2 velocity;
        Animation walkingAnimation;
        AnimationPlayer animationPlayer;
        float speed;
        bool jumping;
        bool running;
};