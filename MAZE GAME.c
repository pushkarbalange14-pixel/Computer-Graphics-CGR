#include <graphics.h>
#include <conio.h>
#include <stdio.h>

#define ROWS 12
#define COLS 16
#define SIZE 30

int maze[ROWS][COLS] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,1,0,1,1,1,0,1,0,1,1,0,1},
    {1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1},
    {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1},
    {1,1,1,1,1,0,1,1,1,0,1,1,1,1,0,1},
    {1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1},
    {1,0,1,0,1,1,1,0,1,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void drawMaze()
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (maze[i][j] == 1)
            {
                setfillstyle(SOLID_FILL, BLUE);

                bar(
                    j * SIZE,
                    i * SIZE,
                    (j + 1) * SIZE,
                    (i + 1) * SIZE
                );
            }
            else
            {
                setfillstyle(SOLID_FILL, BLACK);

                bar(
                    j * SIZE,
                    i * SIZE,
                    (j + 1) * SIZE,
                    (i + 1) * SIZE
                );
            }
        }
    }
}

void drawPlayer(int x, int y)
{
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);

    circle(
        x * SIZE + SIZE / 2,
        y * SIZE + SIZE / 2,
        9
    );

    floodfill(
        x * SIZE + SIZE / 2,
        y * SIZE + SIZE / 2,
        YELLOW
    );
}

int main()
{
    int gd = DETECT
