#include "raylib.h"
#include "raymath.h"
#include "game.h"
#include "assetManager.h"

int main()
{
    InitWindow(1280, 720, "Find Their Girlfriends");
    
    AssetManager::LoadAssets();

    SetTargetFPS(0);

    Game game;
    float dt;

    while (!WindowShouldClose())
    {
        dt = GetFrameTime();
        dt = Clamp(dt, 0.0f, 0.05f);
        game.update(dt);
        game.draw();
    }

    AssetManager::UnloadAssets();

    return 0;
}