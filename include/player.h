#pragma once

#include "raylib.h"
#include "raymath.h"
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
        Animation sprintAnimation;
        Animation jumpingAnimation;
        Animation idleAnimation;
        AnimationPlayer animationPlayer;
        float speed;
        float sprintSpeed;
        float jumpSpeed;
        bool facingLeft;
        bool grounded;
        bool sprinting;
};