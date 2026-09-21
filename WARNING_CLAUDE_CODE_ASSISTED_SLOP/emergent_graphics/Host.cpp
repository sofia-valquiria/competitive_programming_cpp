#include "raylib.h"
#include "Logic.h"
#include <windows.h>
#include <iostream>
#include <sys/stat.h>

typedef void (*UpdateAndDrawFunc)(AppState*);

struct FileInfo {
    long long lastModified;
};

long long GetFileModificationTime(const char* path) {
    struct stat result;
    if (stat(path, &result) == 0) {
        return result.st_mtime;
    }
    return 0;
}

int main() {
    InitWindow(800, 600, "Emergent Complexity - Polar Hot Reload");
    SetTargetFPS(60);

    AppState state = { 0.0f, 3.0f, 100 };

    HMODULE hLogic = NULL;
    UpdateAndDrawFunc updateAndDraw = nullptr;
    long long lastModTime = 0;

    while (!WindowShouldClose()) {
        // 1. Check for DLL updates
        long long currentModTime = GetFileModificationTime("logic.dll");
        if (currentModTime != lastModTime) {
            if (hLogic) FreeLibrary(hLogic);

            hLogic = LoadLibrary("logic.dll");
            if (hLogic) {
                updateAndDraw = (UpdateAndDrawFunc)GetProcAddress(hLogic, "UpdateAndDraw");
                std::cout << "DLL Reloaded!" << std::endl;
            }
            lastModTime = currentModTime;
        }

        // 2. Handle basic commands for hot-parameter tuning
        if (IsKeyDown(KEY_UP)) state.complexityFactor += 0.1f;
        if (IsKeyDown(KEY_DOWN)) state.complexityFactor -= 0.1f;
        if (IsKeyDown(KEY_RIGHT)) state.entityCount += 1;
        if (IsKeyDown(KEY_LEFT)) state.entityCount -= 1;

        // 3. Render
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (updateAndDraw) {
            updateAndDraw(&state);
        } else {
            DrawText("Waiting for logic.dll...", 10, 10, 20, GRAY);
        }

        DrawText("Arrows: Tweak Complexity & Count", 10, 570, 20, DARKGRAY);
        DrawText("Edit Logic.cpp and rebuild logic.dll to hot-reload math!", 10, 10, 20, BLUE);

        EndDrawing();
    }

    if (hLogic) FreeLibrary(hLogic);
    CloseWindow();

    return 0;
}
