#include <graphics.h>
#include <conio.h>
#include <math.h>

#define PI 3.14159265

void drawPlanet(int cx, int cy, int orbit,
                int radius, float angle, int color)
{
    int x, y;

    x = cx + (int)(orbit * cos(angle));
    y = cy + (int)(orbit * sin(angle));

    setcolor(color);
    circle(x, y, radius);
    setfillstyle(SOLID_FILL, color);
    floodfill(x, y, color);
}

int main()
{
    int gd = DETECT;
    int gm;

    int cx, cy;

    float mercury = 0;
    float venus = 0;
    float earth = 0;
    float mars = 0;
    float jupiter = 0;
    float saturn = 0;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    cx = getmaxx() / 2;
    cy = getmaxy() / 2;

    while (!kbhit())
    {
        cleardevice();

        /* ORBITS */

        setcolor(DARKGRAY);

        circle(cx, cy, 60);
        circle(cx, cy, 90);
        circle(cx, cy, 125);
        circle(cx, cy, 160);
        circle(cx, cy, 210);
        circle(cx, cy, 260);

        /* SUN */

        setcolor(YELLOW);
        circle(cx, cy, 25);

        setfillstyle(SOLID_FILL, YELLOW);
        floodfill(cx, cy, YELLOW);

        /* PLANETS */

        drawPlanet(
            cx, cy,
            60,
            5,
            mercury,
            LIGHTGRAY
        );

        drawPlanet(
            cx, cy,
            90,
            7,
            venus,
            LIGHTRED
        );

        drawPlanet(
            cx, cy,
            125,
            9,
            earth,
            BLUE
        );

        drawPlanet(
            cx, cy,
            160,
            7,
            mars,
            RED
        );

        drawPlanet(
            cx, cy,
            210,
            13,
            jupiter,
            BROWN
        );

        drawPlanet(
            cx, cy,
            260,
            11,
            saturn,
            LIGHTCYAN
        );

        /* PLANET LABEL */

        setcolor(WHITE);

        outtextxy(10, 10,
                  "3D STYLE SOLAR SYSTEM SIMULATION");

        /* UPDATE ORBIT ANGLES */

        mercury += 0.08;
        venus   += 0.055;
        earth   += 0.04;
        mars    += 0.03;
        jupiter += 0.015;
        saturn  += 0.01;

        delay(30);
    }

    getch();
    closegraph();

    return 0;
}
