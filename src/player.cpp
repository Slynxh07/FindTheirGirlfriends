#include "player.h"

Player::Player()
{
    velocity = { 0, 0 };
    pos = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
    speed = 100.0f;
    walkingAnimation = Animation(LoadTexture("resources/playerSprite/Walking.png"), 6, 
    std::vector<Rectangle>{ {0, 0, 128, 128 }, {128, 0, 128, 128 }, {256, 0, 128, 128 }, {384, 0, 128, 128 }, {512, 0, 128, 128 }, {640, 0, 128, 128 }, 
    {768, 0, 128, 128 }, {896, 0, 128, 128 }, {1024, 0, 128, 128 }, {1152, 0, 128, 128 }, {1280, 0, 128, 128 }, {1408, 0, 128, 128 } }, 12, 1);
    idleAnimation = Animation(LoadTexture("resources/playerSprite/Walking.png"), 
    1, std::vector<Rectangle>{{ 384, 0, 128, 128 }}, 1, 0);
    animationPlayer.setAnimation(idleAnimation);
}

void Player::draw()
{
    Rectangle destRect = { pos.x, pos.y, 128, 128 };
    animationPlayer.playAnimation(destRect, { 64, 64 }, 0, WHITE);
}

void Player::update(float dt)
{
    float move = (IsKeyDown(KEY_D) ? 1.0f : 0.0f) - (IsKeyDown(KEY_A) ? 1.0f : 0.0f);

    velocity.x = move * speed * dt;

    animationPlayer.setAnimation(move != 0 ? walkingAnimation : idleAnimation);

    pos.x += velocity.x;
}