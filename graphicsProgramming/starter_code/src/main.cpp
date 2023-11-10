#include <raylib.h>

const int screenWidth = 800;
const int screenHeight = 600;

int main() {
    InitWindow(screenWidth, screenHeight, "Pac-Man Maze");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(GREEN);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
