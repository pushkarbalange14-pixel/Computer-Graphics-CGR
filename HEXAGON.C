#include <graphics.h>
#include <conio.h>

void flood(int x, int y, int o, int n)
{
    if (getpixel(x, y) == o)
    {
        putpixel(x, y, n);
        delay(3);

        flood(x+1, y, o, n);
        flood(x-1, y, o, n);
        flood(x, y+1, o, n);
        flood(x, y-1, o, n);
        flood(x-1, y-1, o, n);
        flood(x+1, y-1, o, n);
        flood(x-1, y+1, o, n);
        flood(x+1, y+1, o, n);
    }
}

void main()
{
    int gd = DETECT, gm;

    int points[] = {280,180, 320,180, 340,210, 320,240, 280,240, 260,210, 280,180};

    int o = 0;
    int n = 4;
    int x = 282;
    int y = 182;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    drawpoly(7, points);


    flood(x, y, o, n);

    getch();
    closegraph();
}
