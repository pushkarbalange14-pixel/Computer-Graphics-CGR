#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    rectangle(200, 150, 500, 350);

    getch();
    closegraph();

    return 0;
}
