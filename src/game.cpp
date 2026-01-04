#include "game.h"

Game::Game()
{
    running = true;
    currLevel = Level(1, std::vector<NPC>{john});
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