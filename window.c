#include <stdio.h>
#include "raylib.h"

int main() {
    const int width = 800;
    const int height = 1000;
    const char* title = "MyCalc";
    int currentOutput = 0;
    char outputBuffer[32];

    char* getOutputString() {
        if(sprintf(outputBuffer, "%d", currentOutput) > 0) return outputBuffer;
        return nullptr;
    }

    InitWindow(width, height, title);

    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);
        DrawText(getOutputString(), 20, 20, 50, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}