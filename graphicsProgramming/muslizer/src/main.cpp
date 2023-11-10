#include <raylib.h>
#include <iostream>
#include <cmath>
#include<vector>

const int screenWidth = 800;
const int screenHeight = 600;

int main() {
    InitWindow(screenWidth, screenHeight, "Music Visualizer");
    SetTargetFPS(60);

    InitAudioDevice();
    Sound sound  = LoadSound("resources/xxx.wav");
    Wave wave = LoadWave("resources/xxx.wav");

    int samplesCount = wave.sampleSize;
    int stride = screenWidth/samplesCount;
    std::vector<short> waveData((short*)wave.data,  (short*)wave.data + samplesCount);
    PlaySound(sound);

    while (!WindowShouldClose()) {
        BeginDrawing();
        Color customColor = (Color){69, 233, 254, 255};
        ClearBackground(customColor);

        for(int i=1; i < samplesCount; ++i){
            int x1 = (i - 1) * stride;
            int waveHeight = (waveData[i]/32768.0f)*500 * sin(GetTime()*9);
            int y1 = screenHeight - waveHeight;
            Color lineColor = ColorFromHSV((float)y1, 1.0f, 1.0f);
            DrawRectangle(x1,y1, stride, waveHeight , lineColor);
        }
        EndDrawing();
    }

    UnloadSound(sound);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
