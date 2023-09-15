#include <cstdint>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#define WINDOW_WIDTH 1366
#define WINDOW_HEIGHT 768

int main() {
    printf("Hello, raylib (+ raygui)!\n");

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "raylib [core] example - basic window");
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    int listViewScrollIndex = 0;
    int listViewActive = -1;

    constexpr const char* str = "Congrats! You created your first window!";
    constexpr float fontSize = 20.0f;
    Vector2 textSize = MeasureTextEx(GetFontDefault(), str,fontSize, 1.0f);

    int32_t windowWidth = WINDOW_WIDTH;
    int32_t windowHeight = WINDOW_HEIGHT;

    while (!WindowShouldClose()) {
        if(IsWindowResized()) {
            windowWidth = GetRenderWidth();
            windowHeight = GetRenderHeight();
            printf("%d, %d\n", windowWidth, windowHeight);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        GuiWindowBox({0, 0, (float)windowWidth, (float)windowHeight}, "lowercase_michael");

        GuiPanel({150, 150, 300, 300}, "lower_case__michael");

        // GuiListView((Rectangle){ 165, 25, 140, 124 }, "Charmander;Bulbasaur;#18#Squirtel;Pikachu;Eevee;Pidgey", &listViewScrollIndex, &listViewActive);
        int32_t x = (int32_t)((float)windowWidth / 2.0f) - (textSize.x / 2.0f); 
        int32_t y = (int32_t)((float)windowHeight / 2.0f) - (textSize.y / 2.0f);
        DrawText("Congrats! You created your first window!", x, y, fontSize, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}