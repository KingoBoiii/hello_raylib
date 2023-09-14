#include <vk.h>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main() {
    print("Hello, raylib (+ raygui)!");

    InitWindow(800, 450, "raylib [core] example - basic window");

    int listViewScrollIndex = 0;
    int listViewActive = -1;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        GuiListView((Rectangle){ 165, 25, 140, 124 }, "Charmander;Bulbasaur;#18#Squirtel;Pikachu;Eevee;Pidgey", &listViewScrollIndex, &listViewActive);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}