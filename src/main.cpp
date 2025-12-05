// including libraries which will be used in the program
#include <iostream>
#include "raylib.h"

// including header files which lead to class program files
#include "player.hpp"
#include "map.hpp"

// main program

int main()
{
    // Declaring variables which can be interpreted as settings
    const float speed = 300.0f;
    const float playerSize = 40;
    const float windowW = 800;
    const float windowH = 600;
    float tileSize = 200.0f;
    const int mapWidth = 10;
    const int mapHeight = 10;
    
    // tile map for creating the map
    int tileMap[mapHeight][mapWidth];
    
    // initialising the window with a title
    InitWindow(windowW,windowH,"Object Test");
    // caps the fps
    SetTargetFPS(60);

    // uses my player class to create a player rectangle.
    Player player(0,0,speed,playerSize,WHITE);

    // creating a render/frame loop
    while (!WindowShouldClose())
    {
        // What tells the code what is being rendered in a frame
        BeginDrawing();
        ClearBackground(BLUE); // stating the colour of the background

        player.update(); // a method from my player class file which handles movement.
        player.draw();  // a method from my player class file which handles drawing the character.

        std::cout << GetFPS() << std::endl; // outputs the frames per second

        EndDrawing(); // ends the frame loop
    }

    return 0; // ends the main program.
}