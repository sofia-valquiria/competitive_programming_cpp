#include "Logic.h"
#include <cmath>
#include <vector>

extern "C" {
    __declspec(dllexport) void UpdateAndDraw(AppState* state) {
        state->time += 0.01f;

        // Example of emergent complexity using polar coordinates
        // We create a pattern that evolves over time
        for (int i = 0; i < state->entityCount; ++i) {
            float angle = (float)i * (2.0f * 3.14159f / state->entityCount);

            // The "Complexity" formula:
            // Radius depends on angle, time, and our complexity factor
            float r = 200.0f * (1.0f + 0.5f * sinf(state->complexityFactor * angle + state->time));

            // Polar to Cartesian conversion
            float x = 400.0f + r * cosf(angle);
            float y = 300.0f + r * sinf(angle);

            DrawCircleV({x, y}, 2.0f, MAROON);
        }
    }
}
