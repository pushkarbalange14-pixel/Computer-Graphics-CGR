#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    circle(300, 200, 100);

    getch();
    closegraph();

    return 0;
}
