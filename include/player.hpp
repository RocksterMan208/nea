#pragma once

#include "raylib.h"
#include "raymath.h"

class Player
{
    public:
        float size;
        float speed;
        Vector2 pos;
        Color color;

    Player(float x, float y, float speed, float size, Color color);

    void update();
    void draw();
    float center();
};

