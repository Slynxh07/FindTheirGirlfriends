#include "player.h"
#include <iostream>

Player::Player()
{
    velocity = { 0, 0 };
    pos = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
    speed = 100.0f;
    sprintSpeed = 300.0f;
    jumpSpeed = -500.0f;
    facingLeft = false;
    grounded = true;
    sprinting = false;
    idleAnimation = Animation(LoadTexture("resources/playerSprite/Walking.png"), 
    1, std::vector<Rectangle>{{ 384, 0, 128, 128 }}, 1, 0);
    walkingAnimation = Animation(LoadTexture("resources/playerSprite/Walking.png"), 12, 
    std::vector<Rectangle>{ {0, 0, 128, 128 }, {128, 0, 128, 128 }, {256, 0, 128, 128 }, {384, 0, 128, 128 }, {512, 0, 128, 128 }, {640, 0, 128, 128 }, 
    {768, 0, 128, 128 }, {896, 0, 128, 128 }, {1024, 0, 128, 128 }, {1152, 0, 128, 128 }, {1280, 0, 128, 128 }, {1408, 0, 128, 128 } }, 12, 1);
    jumpingAnimation = Animation(LoadTexture("resources/playerSprite/Jumping.png"), 12,
    std::vector<Rectangle> { {0, 0, 128, 128 }, {128, 0, 128, 128 }, {256, 0, 128, 128 }, {384, 0, 128, 128 }, {512, 0, 128, 128 }, {640, 0, 128, 128 }, 
    {768, 0, 128, 128 }, {896, 0, 128, 128 }, {1024, 0, 128, 128 }, {1152, 0, 128, 128 } }, 10, 2);
    sprintAnimation = Animation(LoadTexture("resources/playerSprite/Running.png"), 18,
    std::vector<Rectangle>{ {0, 0, 128, 128 }, {128, 0, 128, 128 }, {256, 0, 128, 128 }, {384, 0, 128, 128 }, {512, 0, 128, 128 }, {640, 0, 128, 128 }, 
    {768, 0, 128, 128 }, {896, 0, 128, 128 }, {1024, 0, 128, 128 }, {1152, 0, 128, 128 }, {1280, 0, 128, 128 }, {1408, 0, 128, 128 } }, 12, 3);
    animationPlayer.setAnimation(idleAnimation);
}

void Player::draw()
{
    Rectangle destRect = { pos.x, pos.y, 128, 128 };
    animationPlayer.playAnimation(destRect, { 64, 64 }, 0, WHITE, facingLeft);
}

void Player::update(float dt)
{
    if (pos.y > GetScreenHeight() - 64) grounded = true;
    else grounded = false;

    velocity.y += 1750 * dt;

    float dir = (IsKeyDown(KEY_D) ? 1.0f : 0.0f) - (IsKeyDown(KEY_A) ? 1.0f : 0.0f);

    if (grounded)
    {
        if (velocity.y > 0) velocity.y = 0;

        if (IsKeyPressed(KEY_SPACE)) velocity.y = jumpSpeed;

        if (IsKeyDown(KEY_LEFT_SHIFT)) sprinting = true;
        else sprinting = false;

        if (grounded) animationPlayer.setAnimation(dir != 0 ? (sprinting ? sprintAnimation : walkingAnimation) : idleAnimation);
    }
    else animationPlayer.setAnimation(jumpingAnimation);

    velocity.x = dir * (sprinting ? sprintSpeed : speed);

    if (velocity.x < 0) facingLeft = true;
    else if (velocity.x > 0) facingLeft = false;

    pos.x += velocity.x  * dt;
    pos.y += velocity.y * dt;
}