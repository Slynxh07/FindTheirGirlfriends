#include "npc.h"

NPC::NPC()
{
    id = 0;
    name = "null";
    pos = { 360.0f, 500.0f };
    velocity = { 0, 0 };
    hitBox = { pos.x, pos.y, 30, 50 };
}

NPC::NPC(int id, std::string name, Rectangle hitbox, Vector2 pos, Vector2 velocity)
{
    this->id = id;
    this->name = name;
    this->hitBox = hitBox;
    this->pos = pos;
    this->velocity = velocity;
}

NPC::NPC(int id, std::string name, Rectangle hitBox, Vector2 pos, Vector2 velocity, Animation walking, Animation idle)
{
    this->id = id;
    this->name = name;
    this->hitBox = hitBox;
    this->pos = pos;
    this->velocity = velocity;
    this->walking = walking;
    this->idle = idle;
}

void NPC::draw()
{
    DrawRectangleRec(hitBox, RED);
}

void NPC::update()
{
    //will be virtual? - so this should be an interface maybe?
}

int NPC::getID()
{
    return id;
}