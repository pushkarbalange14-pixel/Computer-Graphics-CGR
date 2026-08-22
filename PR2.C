#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include<stdlib.h>

void main()
{
    int gd = DETECT, gm;
    int x1, x2, y1, y2, dx, dy, max;
    int i;
    float x, y, x_ine, y_ine;

    clrscr();

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    printf("\nEnter the x1 and y1: ");
    scanf("%d %d", &x1, &y1);

    printf("\nEnter the x2 and y2: ");
    scanf("%d %d", &x2, &y2);

    dx = x2 - x1;
    dy = y2 - y1;

    // steps calculation
    max = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);


    x_ine = (float)dx / max;
    y_ine = (float)dy / max;

    x = x1;
    y = y1;

    for (i = 0; i <= max; i++)
    {
        putpixel((int)x, (int)y, WHITE);

        x = x + x_ine;
        y = y + y_ine;
    }

    getch();
    closegraph();
}
