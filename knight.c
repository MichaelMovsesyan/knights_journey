#include "knight.h"
#include <stdlib.h>

KnightGrid init_knight_grid() {

  KnightGrid kgrid;

  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      kgrid.grid[i][j] = DEAD;
    }
  }
  return kgrid;
}

Knight init_knight() {

  Knight knight;
  knight.dir = 0;
  knight.x = WIDTH / 2;
  knight.y = HEIGHT / 2;

  return knight;
}

void init_grid(KnightGrid *kgrid, Knight *knight) {
  kgrid->grid[knight->x][knight->y] = ALIVE;
}

void draw_knight_grid(KnightGrid *kgrid, Texture2D ktexture, Rectangle source,
                      int start_x, int start_y) {

  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      if (kgrid->grid[i][j] == DEAD) {
        DrawRectangle(start_x + (CELL_WIDTH + SPACING_X) * i,
                      start_y + (CELL_HEIGHT + SPACING_Y) * j, CELL_WIDTH,
                      CELL_HEIGHT, BLACK);
      } 
      else if (kgrid->grid[i][j] == CURRENT) {
        // DrawRectangle(start_x + (CELL_WIDTH + SPACING_X) * i, start_y +
        // (CELL_HEIGHT + SPACING_Y) * j, CELL_WIDTH, CELL_HEIGHT, RAYWHITE);
        Rectangle dest = {start_x + (CELL_WIDTH + SPACING_X) * i, start_y + (CELL_HEIGHT + SPACING_Y) * j, CELL_WIDTH, CELL_HEIGHT};

        DrawTexturePro(ktexture, source, dest, (Vector2){0, 0}, 0.0f, WHITE);
      }
      else {
        DrawRectangle(start_x + (CELL_WIDTH + SPACING_X) * i, start_y + (CELL_HEIGHT + SPACING_Y) * j, CELL_WIDTH, CELL_HEIGHT, RAYWHITE);
      }
    }
  }
}

void move(Knight *knight) {

  if (knight->dir == 0) {
    knight->x += 1;
    knight->y += 2;
  } else if (knight->dir == 1) {
    knight->x += 2;
    knight->y += 1;
  } else if (knight->dir == 2) {
    knight->x += 2;
    knight->y -= 1;
  } else if (knight->dir == 3) {
    knight->x += 1;
    knight->y -= 2;
  } else if (knight->dir == 4) {
    knight->x -= 1;
    knight->y -= 2;
  } else if (knight->dir == 5) {
    knight->x -= 2;
    knight->y -= 1;
  } else if (knight->dir == 6) {
    knight->x -= 2;
    knight->y += 1;
  } else if (knight->dir == 7) {
    knight->x -= 1;
    knight->y += 2;
  }

  knight->x = (knight->x + WIDTH) % WIDTH;
  knight->y = (knight->y + HEIGHT) % HEIGHT;
}

void update_grid(KnightGrid *kgrid, Knight *knight) {
  int x = knight->x;
  int y = knight->y;

  kgrid->grid[x][y] = ALIVE;

  for (int i = 0; i < 8; i++) {

      int dir = rand() % 8;
      knight->dir = dir;

      move(knight);

      if (kgrid->grid[knight->x][knight->y] == ALIVE) {
          // Invalid move — go back to original position
          knight->x = x;
          knight->y = y;
      }
      else {
          // Valid move — we're done
          break;
      }
  }

  kgrid->grid[knight->x][knight->y] = CURRENT;
}