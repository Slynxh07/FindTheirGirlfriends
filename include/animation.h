#pragma once

#include "raylib.h"
#include <vector>

class Animation {
    public:
        Animation();
        Animation(Texture2D texture, int framesPerSecond, std::vector<Rectangle>, int length);
        int getFPS();
        int getRectLength();
        std::vector<Rectangle> getRects();
        Texture2D getAtlas();
    private:
        std::vector<Rectangle> rectangles;
        Texture2D textureAtlas;
        int framesPerSecond;
        int rectanglesLength;
};