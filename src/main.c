#include "raylib.h"

int main() {

    // Init
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib Window");

    SetTargetFPS(60);

    // Game Loop
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("Deneme 1,2,3", 40, 40, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
}
