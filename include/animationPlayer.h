#pragma once

#include "animation.h"
#include "raylib.h"
#include <optional>
#include <iostream>

class AnimationPlayer {
    public:
        AnimationPlayer();
        void setAnimation(Animation animation);
        void playAnimation(Rectangle dest, Vector2 origin, float rotation, Color tint, bool flip);
    private:
        std::optional<Animation> animation;
        std::vector<Rectangle> rects;
};