#ifndef LOGIC_H
#define LOGIC_H

#include "raylib.h"

// We use a struct to maintain state between reloads
struct AppState {
    float time;
    float complexityFactor;
    int entityCount;
};

// The function we will hot-reload
extern "C" {
    __declspec(dllexport) void UpdateAndDraw(AppState* state);
}

#endif
