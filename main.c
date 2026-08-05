#include "knight.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  srandom(time(NULL));

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "s");

  Texture2D ktexture = LoadTexture("assets/knight.png");

  printf("id=%u width=%d height=%d\n",
       ktexture.id,
       ktexture.width,
       ktexture.height);

  Rectangle source = {
    0,
    0,
    ktexture.width,
    ktexture.height
};

  KnightGrid kgrid = init_knight_grid();
  Knight knight = init_knight();

//   int count = 0;
//   while (true) {
//     kgrid = init_knight_grid();
//     knight = init_knight();
//   for (int i = 0; i < (WIDTH * HEIGHT); i++) {
//     update_grid(&kgrid, &knight);
//   }
//   printf("I made it %d\n", count++);
// }

  // for (int i = 0; i <= 5; i++) {
  //   update_grid(&kgrid, &knight);
  //   WaitTime(1);
  // }

  
  
  int updates = 0;
  int max_updates = 25;

  while (!WindowShouldClose()) {
    init_grid(&kgrid, &knight);
    if (updates < max_updates) {
      update_grid(&kgrid, &knight);
      updates++;
    }

    BeginDrawing();
    ClearBackground(BLACK);

    int start_x = 0;
    int start_y = 0;

    draw_knight_grid(&kgrid, ktexture, source, start_x, start_y);
    WaitTime(1);

    EndDrawing();
  }
  UnloadTexture(ktexture);
  CloseWindow();
  return 0;
}