#include "raylib.h"



void grid()
{
    int basx = -100000;
    int basy = 100000;
    while (basx <= 100000)
    {
        DrawLine(basx, basy, basx, basy - 200000, BLACK);
        basx = basx + 100;
    }
    basx = -100000;
    basy = 100000;
    while (basy >= -100000)
    {
        DrawLine(basx, basy, basx + 200000, basy, BLACK);
        basy = basy - 100;
    }
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1600;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - cubic-bezier lines");

    int cx, cy = 0;
    Camera2D camera = {0};
    camera.target = (Vector2){cx, cy};



    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        if (IsKeyDown(KEY_RIGHT))
        {
            cx += 2;
        }
        else if (IsKeyDown(KEY_LEFT))
        {
            cx -= 2;
        }

        camera.target = (Vector2){ cx, cy };

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode2D(camera);
        grid();
        EndMode2D();

        EndDrawing();
    }

    CloseWindow();        // Close window

    return 0;
}
