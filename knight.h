#ifndef KNIGHT_H
#define KNIGHT_H

#include <stdbool.h>

#define ALIVE true
#define DEAD false

#define WIDTH 75
#define HEIGHT 75

#define CELL_WIDTH 10
#define CELL_HEIGHT 10

#define SPACING_X 5
#define SPACING_Y 5

#define SCREEN_WIDTH (CELL_WIDTH + SPACING_X) * WIDTH
#define SCREEN_HEIGHT  (CELL_HEIGHT + SPACING_Y) * HEIGHT

typedef struct {
    bool grid[WIDTH][HEIGHT];
} KnightGrid;

KnightGrid init_knight_grid();

#endif // KNIGHT_H