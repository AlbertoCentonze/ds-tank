#ifndef GRID_H // This is to avoid reinclusion due to header reinclusion
#define GRID_H

#include <nds.h>

// Grid logic
#define GRID_WIDTH 15  // 32
#define GRID_HEIGHT 10 // 24

typedef int Grid[GRID_WIDTH][GRID_HEIGHT];

void print_grid();
void clear_grid();
void update_grid();

// Tank logic
#define PLAYER_TAG 1

enum Direction {
    IDLE,
    UP,
    DOWN, 
    RIGHT,
    LEFT,
};

void move_tank(int i, int j, int d);

typedef struct {
    int x;
    int y;
    int direction;
    int fire;
    // potentially firing state?
} TankState;

// Utils
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define GRID(x, y) grid[(y)][(x)]

#define WAIT for (int i = 0; i < 10000000; ++i) {}
#define MOVE_COORDS(x, y, dir) \
    switch (dir)               \
    {                          \
    case RIGHT:                \
        j += 1;                \
        break;                 \
    case LEFT:                 \
        j -= 1;                \
        break;                 \
    case UP:                   \
        i -= 1;                \
        break;                 \
    case DOWN:                 \
        i += 1;                \
        break;                 \
    }

#endif // GRID_H
