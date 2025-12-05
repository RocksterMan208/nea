#include "player.hpp"

Player::Player(float x, float y, float objectSpeed, float objectSize, Color objectColor)
{
    pos = {x,y};
    size = objectSize;
    speed = objectSpeed;
    color = objectColor;
}

void Player::update()
{
    float dt = GetFrameTime();
    Vector2 dir {0, 0};

    // Move Up
    if (IsKeyDown(KEY_W)) dir.y -= 1;

    // Move Down
    if (IsKeyDown(KEY_S)) dir.y += 1;

    // Move Left
    if (IsKeyDown(KEY_A)) dir.x -= 1;

    // Move Right
    if (IsKeyDown(KEY_D)) dir.x += 1;

    if (dir.x != 0 || dir.y != 0)
    {
        dir = Vector2Normalize(dir);
    }

    pos.x += dir.x * speed * dt;
    pos.y += dir.y * speed * dt;

}

void Player::draw()
{
    DrawRectangleV(pos, {size,size}, color);
}

float Player::center()
{
    return size/2;
}