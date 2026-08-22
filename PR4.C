#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void main()
{
    int gd = DETECT, gm;
    int xc, yc, r, x, y, d;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    printf("Enter xc, yc and radius: ");
    scanf("%d%d%d", &xc, &yc, &r);

    x = 0;
    y = r;
    d = 3 - 2 * r;

    while (x <= y)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        if (d < 0)
            d = d + 4 * x + 6;
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }

        x++;
    }

    getch();
    closegraph();


}
