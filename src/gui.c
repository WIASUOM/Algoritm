// Include && Libraries
#include <raylib.h>

// Grid Background
void grid(){
	int gridx, gridy;
	gridx = -10000;
	gridy = 10000;
	while(gridx <= 10000){
	    DrawLine(gridx, gridy, gridx, -gridy, BLACK);
		gridx = gridx + 100;
	}
	while(gridy >= -10000){
	    DrawLine(gridx, gridy, -gridx, gridy, BLACK);
		gridy = gridy - 100;
	}
}

// Main Function
int main () {

    const int SCREEN_WIDTH = 1200;
    const int SCREEN_HEIGHT = 800;


    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "My first RAYLIB program!");
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    MaximizeWindow();
    SetTargetFPS(60);


    Rectangle player = { 0, 0, 0, 0 };

    Camera2D camera = { 0 };
    camera.target = (Vector2){ player.x + 20.0f, player.y + 20.0f };
    camera.offset = (Vector2){ SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;


    while (WindowShouldClose() == false){

        if (IsKeyDown(KEY_RIGHT)) player.x += 127;
        else if (IsKeyDown(KEY_LEFT)) player.x -= 127;
        else if (IsKeyDown(KEY_DOWN)) player.y += 127;
        else if (IsKeyDown(KEY_UP)) player.y -= 127;

        // Camera target follows player
        camera.target = (Vector2){ player.x + 20, player.y + 20 };

        BeginDrawing();
            ClearBackground(WHITE);
            BeginMode2D(camera);
                grid();

                DrawRectangleRec(player, RED);

            EndMode2D();

        EndDrawing();
    }

    CloseWindow();
}
