#include "assetManager.h"

Texture AssetManager::playerIdle;
Texture AssetManager::playerWalking;
Texture AssetManager::playerSprinting;
Texture AssetManager::playerJumping;

void AssetManager::LoadAssets()
{
    playerIdle = LoadTexture("resources/playerSprite/Walking.png");
    playerWalking = LoadTexture("resources/playerSprite/Walking.png");
    playerSprinting = LoadTexture("resources/playerSprite/Running.png");
    playerJumping = LoadTexture("resources/playerSprite/Jumping.png");
}

void AssetManager::UnloadAssets()
{
    UnloadTexture(playerIdle);
    UnloadTexture(playerWalking);
    UnloadTexture(playerSprinting);
    UnloadTexture(playerJumping);
}