#include "animationPlayer.h"

AnimationPlayer::AnimationPlayer()
{
    animation = std::nullopt;
}

void AnimationPlayer::setAnimation(Animation animation)
{
    if (this->animation.has_value() && this->animation.value().getID() == animation.getID()) return;
    this->animation = animation;
    this->rects = animation.getRects();
}

void AnimationPlayer::playAnimation(Rectangle dest, Vector2 origin, float rotation, Color tint, bool flip)
{
    if (!animation.has_value())
    {
        std::cout << "No animation assigned";
        return;
    }
    int index = (int)(GetTime() * animation->getFPS()) % animation->getRectLength();

    Rectangle source = rects.at(index);

    if (flip)
    {
        source.x += source.width;
        source.width *= -1;
    }

    DrawTexturePro(animation->getAtlas(), source, dest, origin, rotation, tint);
}