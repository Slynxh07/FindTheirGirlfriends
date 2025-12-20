#include "player.h"

Player::Player()
{
    velocity = { 0, 0 };
    pos = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
    jumping = false;
    running = false;
    speed = 100.0f;
    walkingAnimation = Animation(LoadTexture("resources/playerSprite/Walking.png"), 6, 
    std::vector<Rectangle>{ {0, 0, 128, 128 }, {128, 0, 128, 128 }, {256, 0, 128, 128 }, {384, 0, 128, 128 }, {512, 0, 128, 128 }, {640, 0, 128, 128 }, 
    {768, 0, 128, 128 }, {896, 0, 128, 128 }, {1024, 0, 128, 128 }, {1152, 0, 128, 128 }, {1280, 0, 128, 128 }, {1408, 0, 128, 128 } }, 12);
    animationPlayer.setAnimation(walkingAnimation);
}

void Player::draw()
{
    Rectangle destRect = { pos.x, pos.y, 128, 128 };
    //DrawTexturePro(atlas, textureRect, destRect, Vector2{64, 64}, 0, WHITE);
    animationPlayer.playAnimation(destRect, { 64, 64 }, 0, WHITE);
}

void Player::update(float dt)
{
    if (IsKeyDown(KEY_A)) 
    {
        velocity.x = -speed * dt;
        running = true;
    } 
    else if (IsKeyDown(KEY_D))
    {
        velocity.x = speed * dt;
        running = true;
    } 
    else 
    {
        velocity.x = 0;
        running = false;
    }

    pos.x += velocity.x;
}