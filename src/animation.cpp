#include "animation.h"

Animation::Animation() {}

Animation::Animation(Texture2D texture, int framesPerSecond, std::vector<Rectangle> rects, int length)
{
    this->textureAtlas = texture;
    this->framesPerSecond = framesPerSecond;
    this->rectangles = rects;
    this->rectanglesLength = length;
}

int Animation::getFPS()
{
    return framesPerSecond;
}

int Animation::getRectLength()
{
    return rectanglesLength;
}

std::vector<Rectangle> Animation::getRects()
{
    return rectangles;
}

Texture2D Animation::getAtlas()
{
    return textureAtlas;
}