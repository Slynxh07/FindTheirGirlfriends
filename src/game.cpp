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
    DrawFPS(10, 10);
    EndDrawing();
}

void Game::update(float dt)
{
    player.update(dt);
}