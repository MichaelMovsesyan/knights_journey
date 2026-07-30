#include "knight.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  srandom(time(NULL));

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "s");

  KnightGrid kgrid = init_knight_grid();
  Knight knight = init_knight();

  for (int i = 0; i <= 5; i++) {
    update_grid(&kgrid, &knight);
  }

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