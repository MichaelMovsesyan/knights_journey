#include "knight.h"

KnightGrid init_knight_grid() {
    KnightGrid knight;

    int x = WIDTH / 2;
    int y = HEIGHT / 2;

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            knight.grid[i][j] = DEAD;
        }
    }
    return knight;
}