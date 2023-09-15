#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main() {
    printf("Hello, raylib (+ raygui)!\n");

    InitWindow(1366, 768, "raylib [core] example - basic window");

    int listViewScrollIndex = 0;
    int listViewActive = -1;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        GuiWindowBox({0, 0, 1366, 768}, "lowercase_michael");

        GuiPanel({150, 150, 300, 300}, "lower_case__michael");

        // GuiListView((Rectangle){ 165, 25, 140, 124 }, "Charmander;Bulbasaur;#18#Squirtel;Pikachu;Eevee;Pidgey", &listViewScrollIndex, &listViewActive);
        DrawText("Congrats! You created your first window!", 
            (int)((float)1366 / 2.0f), 
            (int)((float)768 / 2.0f), 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}