#include <stdio.h>
#include "game.h"

Grid grid = {0};
int direction = RIGHT;

int main(void)
{
    consoleDemoInit();

    GRID(0, 0) = 1;

    while (1)
    {
        WAIT

        consoleClear();
        print_grid();
        swiWaitForVBlank();

        update_grid();
    }
}

// Function definition
void print_grid()
{
    for (int i = 0; i < GRID_HEIGHT; i++)
    {
        for (int j = 0; j < GRID_WIDTH; j++)
        {
            printf("%d", GRID(i, j));
        }
        printf("\n");
    }
}

void update_grid()
{
    // TODO why do I need to store player_x, y outside?
    int player_x = 0, player_y = 0;
    for (int i = 0; i < GRID_WIDTH; i++)
    {
        for (int j = 0; j < GRID_HEIGHT; j++)
        {
            if (GRID(i, j) == PLAYER_TAG)
            {
                player_x = i;
                player_y = j;
                break;
            }
        }
    }
    move_tank(player_x, player_y, direction);
}

void move_tank(int i, int j, int d)
{
    // if (d == IDLE || i == 0 || j == 0 || i == GRID_WIDTH || j == GRID_HEIGHT) return;
    GRID(i, j) = 0;
    printf("old %d %d", i, j);
    MOVE_COORDS(i, j, d)
    GRID(i, j) = 1;
    printf(" new %d %d", i, j);
}
