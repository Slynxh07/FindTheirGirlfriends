#pragma once

#include "raylib.h"
#include "raymath.h"
#include "animation.h"
#include "animationPlayer.h"
#include "assetManager.h"

enum class PlayerState { Idle, Walk, Sprint, Jump };

class Player {
    public:
        Player();
        void draw();
        void update(float dt);

    private:
        void handleInput();
        void applyPhysics(float dt);
        void updateAnimation();
        void checkGroundCollisions();

        Vector2 pos;
        Vector2 velocity;
        Rectangle hitBox;
        Rectangle groundCheck;
        Animation walkingAnimation;
        Animation sprintAnimation;
        Animation jumpingAnimation;
        Animation idleAnimation;
        AnimationPlayer animationPlayer;
        PlayerState currentState;
        float speed;
        float sprintSpeed;
        float jumpSpeed;
        bool facingLeft;
        bool grounded;
        bool sprinting;
        bool jumpRequested;
};