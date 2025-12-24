#pragma once

#include "raylib.h"

class AssetManager {
    public:
        static Texture2D playerIdle;
        static Texture2D playerWalking;
        static Texture2D playerSprinting;
        static Texture2D playerJumping;

        static void LoadAssets();
        static void UnloadAssets();
};