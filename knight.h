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

typedef struct {
    int x, y;
    int dir;
} Knight;

KnightGrid init_knight_grid();

Knight init_knight();

void init_grid(KnightGrid* kgrid, Knight* knight);

void draw_knight_grid(KnightGrid* kgrid, int start_x, int start_y);

void move(Knight* knight);

void make_move(Knight* knight);

void update_grid(KnightGrid* kgrid, Knight* knight);

#endif // KNIGHT_H