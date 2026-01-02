#include "level.h"

Level::Level()
{
    groundObjects = { (Rectangle) { 0, GetScreenHeight() - 30, GetScreenWidth(), 40 } };
}

std::vector<Rectangle> Level::getGroundObjects()
{
    return groundObjects;
}

void Level::draw()
{
    for (Rectangle ground : groundObjects)
    {
        DrawRectangleRec(ground, BLACK);
    }
}