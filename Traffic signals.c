#include <graphics.h>
#include <conio.h>
#include <dos.h>

void drawRoad()
{
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(0, 180, 640, 320);

    setcolor(WHITE);

    line(0, 245, 640, 245);
    line(0, 255, 640, 255);

    line(150, 180, 150, 320);
    line(300, 180, 300, 320);
    line(450, 180, 450, 320);
}

void drawTrafficSignal()
{
    setcolor(WHITE);
    rectangle(500, 40, 570, 170);

    setfillstyle(SOLID_FILL, RED);
    circle(535, 70, 18);
    floodfill(535, 70, WHITE);

    setfillstyle(SOLID_FILL, YELLOW);
    circle(535, 105, 18);
    floodfill(535, 105, WHITE);

    setfillstyle(SOLID_FILL, GREEN);
    circle(535, 140, 18);
    floodfill(535, 140, WHITE);
}

void drawCar(int x, int y, int color)
{
    setcolor(color);

    rectangle(x, y, x + 70, y + 30);

    line(x + 15, y, x + 25, y - 15);
    line(x + 25, y - 15, x + 50, y - 15);
    line(x + 50, y - 15, x + 60, y);

    setfillstyle(SOLID_FILL, color);
    floodfill(x + 5, y + 5, color);

    setcolor(BLACK);

    circle(x + 15, y + 30, 8);
    circle(x + 55, y + 30, 8);

    setfillstyle(SOLID_FILL, BLACK);
    floodfill(x + 15, y + 30, BLACK);
    floodfill(x + 55, y + 30, BLACK);
}

int main()
{
    int gd = DETECT;
    int gm;

    int car1 = -80;
    int car2 = 700;

    initgraph(
        &gd,
        &gm,
        "C:\\TURBOC3\\BGI"
    );

    while (!kbhit())
    {
        cleardevice();

        /* SKY */

        setfillstyle(SOLID_FILL, LIGHTBLUE);
        bar(0, 0, 640, 180);

        /* ROAD */

        drawRoad();

        /* TRAFFIC SIGNAL */

        drawTrafficSignal();

        /* CARS */

        drawCar(car1, 210, RED);
        drawCar(car2, 270, BLUE);

        /* MOVEMENT */

        car1 += 5;
        car2 -= 5;

        if (car1 > 640)
            car1 = -80;

        if (car2 < -80)
            car2 = 700;

        delay(50);
    }

    getch();
    closegraph();

    return 0;
}
