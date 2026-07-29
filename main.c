#include <stdio.h>
#include "knight.h"
#include "raylib.h"

int main(void) {

    InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT, "s");

    KnightGrid kgrid = init_knight_grid();
    Knight knight = init_knight();

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);

        int start_x = 0;
        int start_y = 0;

        init_grid(&kgrid, &knight);
        draw_knight_grid(&kgrid, start_x, start_y);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}