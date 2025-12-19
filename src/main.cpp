#include "raylib.h"
#include "game.h"

int main()
{
    InitWindow(1280, 720, "Find Their Girlfriends");

    Game game;

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        game.update(dt);
        game.draw();
    }

    return 0;
}