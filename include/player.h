#pragma once

#include "raylib.h"

class Player {
    public:
        Player();
        void draw();
        void update(float dt);

    private:
        Vector2 pos;
        Vector2 velocity;
        Texture2D atlas;
        Rectangle textureRect;
        float speed;
        bool jumping;
        bool running;
};