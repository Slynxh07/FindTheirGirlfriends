#include "player.h"
#include <iostream>

constexpr float GRAVITY = 1750.0f;

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
    jumpRequested = false;
    idleAnimation = Animation(AssetManager::playerIdle, 
    1, std::vector<Rectangle>{{ 384, 0, 128, 128 }}, 1, 0);
    walkingAnimation = Animation(AssetManager::playerWalking, 12, 
    std::vector<Rectangle>{ {0, 0, 128, 128 }, {128, 0, 128, 128 }, {256, 0, 128, 128 }, {384, 0, 128, 128 }, {512, 0, 128, 128 }, {640, 0, 128, 128 }, 
    {768, 0, 128, 128 }, {896, 0, 128, 128 }, {1024, 0, 128, 128 }, {1152, 0, 128, 128 }, {1280, 0, 128, 128 }, {1408, 0, 128, 128 } }, 12, 1);
    jumpingAnimation = Animation(AssetManager::playerJumping, 6,
    std::vector<Rectangle> { {0, 0, 128, 128 }, {128, 0, 128, 128 }, {256, 0, 128, 128 }, {384, 0, 128, 128 }, {512, 0, 128, 128 }, {640, 0, 128, 128 }, 
    {768, 0, 128, 128 }, {896, 0, 128, 128 }, {1024, 0, 128, 128 }, {1152, 0, 128, 128 } }, 10, 2);
    sprintAnimation = Animation(AssetManager::playerSprinting, 18,
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
    handleInput();
    applyPhysics(dt);
    updateAnimation();
}

void Player::handleInput()
{
    float dir = (IsKeyDown(KEY_D) ? 1.0f : 0.0f) - (IsKeyDown(KEY_A) ? 1.0f : 0.0f);

    if (grounded) sprinting = IsKeyDown(KEY_LEFT_SHIFT);

    velocity.x = dir * (sprinting ? sprintSpeed : speed);

    jumpRequested = IsKeyPressed(KEY_SPACE);

    if (velocity.x < 0) facingLeft = true;
    else if (velocity.x > 0) facingLeft = false;
}

void Player::applyPhysics(float dt)
{

    if (!grounded) velocity.y += GRAVITY * dt;
    else velocity.y = 0;


    if (jumpRequested && grounded)
    {
        velocity.y = jumpSpeed;
        grounded = false;
    }

    jumpRequested = false;

    pos += velocity * dt;

    if (pos.y > GetScreenHeight() - 64) 
    {
        grounded = true;
    }
    else grounded = false;
}

void Player::updateAnimation()
{
    PlayerState newState;

    if (!grounded)
        newState = PlayerState::Jump;
    else if (velocity.x != 0)
        newState = sprinting ? PlayerState::Sprint : PlayerState::Walk;
    else
        newState = PlayerState::Idle;

    if (newState != currentState)
    {
        currentState = newState;

        switch (currentState)
        {
            case PlayerState::Idle: animationPlayer.setAnimation(idleAnimation); break;
            case PlayerState::Walk: animationPlayer.setAnimation(walkingAnimation); break;
            case PlayerState::Sprint: animationPlayer.setAnimation(sprintAnimation); break;
            case PlayerState::Jump: animationPlayer.setAnimation(jumpingAnimation); break;
        }
    }
}