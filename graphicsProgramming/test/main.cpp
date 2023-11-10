#include <raylib.h>
#include <cmath>

int main() {
    InitWindow(800, 600, "__Testing__");
    SetTargetFPS(60);

    SetWindowState(FLAG_WINDOW_RESIZABLE);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        float width = GetScreenWidth();
        float height  = GetScreenHeight();

        // Camera2D camera = { 0 };
        // camera.target = (Vector2){ width, height };
        // camera.offset = (Vector2){ 0, 0};
        // camera.rotation = 0.0f;
        // camera.zoom = 1.0f;
        // BeginMode2D(camera);

        // for (float t = 0.0f; t < 360.0f; t += 0.01f) {
        //     float x = 16 * powf(sin(t), 3);
        //     float y = 13 * cosf(t) - 5 * cosf(2 * t) - 2 * cosf(3 * t) - cosf(4 * t);
        //     DrawPixel(x, - y, RED);
        // }

        DrawRectangle(100, 100, 200, 200, RED);
        DrawCircle(400, 300, 50, BLUE);

        //EndMode2D();
        EndDrawing();

        if (IsWindowResized()) {
            SetWindowSize(GetScreenWidth(), GetScreenHeight());
        }
    }

    CloseWindow();

    return 0;
}
