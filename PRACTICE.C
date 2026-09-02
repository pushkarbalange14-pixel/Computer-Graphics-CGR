#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main()
{
    int gd = DETECT, gm;
    int x, y;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    printf("Enter coordinates: ");
    scanf("%d%d", &x, &y);

    putpixel(x, y, WHITE);

    setcolor(9);
    line(130, 210, 310, 270);

    getch();
    closegraph();
}
