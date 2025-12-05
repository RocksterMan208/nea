#pragma once

#include "raylib.h"
#include "raymath.h"
#include <iostream>

class Map
{
    public:
        float tileSize;
        Color tileSolid;
        Color tileEmpty;
        int tileMap[10][10];

    Map(float tileSize,int tileMap, Color tileSolid, Color tileEmpty);

    void DrawMap();
};