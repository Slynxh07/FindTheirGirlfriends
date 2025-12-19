#include "player.h"

Player::Player()
{
    velocity = { 0, 0 };
    pos = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
    jumping = false;
    running = false;
    speed = 100.0f;
    atlas = LoadTexture("resources/playerSprite/Walking.png");
    textureRect = { 0, 0, 128, 128 };
}

void Player::draw()
{
    Rectangle destRect = { pos.x, pos.y, 128, 128 };
    DrawTexturePro(atlas, textureRect, destRect, Vector2{64, 64}, 0, WHITE);
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