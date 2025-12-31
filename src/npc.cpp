#include "npc.h"

NPC::NPC(std::string name, Rectangle hitbox, Animation walking, Animation idle)
{
    this->name = name;
    this->hitBox = hitBox;
    this->walking = walking;
    this->idle = idle;
}