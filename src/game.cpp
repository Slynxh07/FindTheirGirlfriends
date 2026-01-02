#include "game.h"

Game::Game()
{
    running = true;
    currLevel = Level();
}

void Game::draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    player.draw();
    currLevel.draw();
    DrawFPS(10, 10);
    EndDrawing();
}

void Game::update(float dt)
{
    player.update(dt, currLevel.getGroundObjects());
}