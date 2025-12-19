#include "game.h"

Game::Game()
{
    running = true;
}

void Game::draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    player.draw();
    EndDrawing();
}

void Game::update(float dt)
{
    player.update(dt);
}