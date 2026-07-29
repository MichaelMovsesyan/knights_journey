#include "knight.h"
#include "raylib.h"

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

void init_grid(KnightGrid* kgrid, Knight* knight) {
    kgrid->grid[knight->x][knight->y] = ALIVE;
}

void draw_knight_grid(KnightGrid* kgrid, int start_x, int start_y) {
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			if (kgrid->grid[i][j] == DEAD) {
				DrawRectangle(start_x + (CELL_WIDTH + SPACING_X) * i, start_y + (CELL_HEIGHT + SPACING_Y) * j, CELL_WIDTH, CELL_HEIGHT, BLACK);
			}
			else {
				DrawRectangle(start_x + (CELL_WIDTH + SPACING_X) * i, start_y + (CELL_HEIGHT + SPACING_Y) * j, CELL_WIDTH, CELL_HEIGHT, RAYWHITE);
			}
		}
	}
}