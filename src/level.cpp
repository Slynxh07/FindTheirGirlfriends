#include "level.h"

Level::Level()
{
    id = 0;
    groundObjects = { Rectangle{ 0, (float)GetScreenHeight() - 30, (float)GetScreenWidth(), 40 } };
    npcs = {};
}

Level::Level(int id)
{
    this->id = id;
    groundObjects = { Rectangle{ 0, (float)GetScreenHeight() - 30, (float)GetScreenWidth(), 40 } };
    npcs = {};
}

Level::Level(int id, const std::vector<NPC>& npcs)
{
    this->id = id;
    groundObjects = { Rectangle{ 0, (float)GetScreenHeight() - 30, (float)GetScreenWidth(), 40 } };
    this->npcs = npcs;
}

const std::vector<Rectangle>& Level::getGroundObjects() const
{
    return groundObjects;
}

void Level::draw()
{
    for (Rectangle ground : groundObjects)
    {
        DrawRectangleRec(ground, BLACK);
    }

    for (NPC npc : npcs)
    {
        npc.draw();
    }
}

void Level::update()
{
    for (NPC npc : npcs)
    {
        npc.update();
    }
}

int Level::getID()
{
    return id;
}