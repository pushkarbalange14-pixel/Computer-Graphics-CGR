#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void drawMenu()
{
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(0, 0, 640, 60);

    setcolor(BLACK);

    rectangle(10, 10, 80, 40);
    outtextxy(25, 23, "LINE");

    rectangle(90, 10, 170, 40);
    outtextxy(105, 23, "RECT");

    rectangle(180, 10, 260, 40);
    outtextxy(195, 23, "CIRCLE");

    rectangle(270, 10, 350, 40);
    outtextxy(285, 23, "FREE");

    rectangle(360, 10, 440, 40);
    outtextxy(375, 23, "FILL");

    rectangle(450, 10, 530, 40);
    outtextxy(465, 23, "ERASE");

    rectangle(540, 10, 620, 40);
    outtextxy(555, 23, "CLEAR");
}

int main()
{
    int gd = DETECT, gm;

    int choice;
    int x1, y1, x2, y2;
    int color = WHITE;

    initgraph(&gd, &gm, "");

    cleardevice();

    drawMenu();

    while (1)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x1, y1);

            /* LINE */
            if (x1 >= 10 && x1 <= 80 &&
                y1 >= 10 && y1 <= 40)
            {
                setcolor(color);

                while (!ismouseclick(WM_LBUTTONDOWN))
                {
                    if (ismouseclick(WM_MOUSEMOVE))
                    {
                        getmouseclick(WM_MOUSEMOVE, x2, y2);
                    }
                }

                getmouseclick(WM_LBUTTONDOWN, x2, y2);

                line(x1, y1, x2, y2);
            }

            /* RECTANGLE */
            else if (x1 >= 90 && x1 <= 170 &&
                     y1 >= 10 && y1 <= 40)
            {
                printf("Rectangle Tool Selected\n");

                printf("Enter x1 y1 x2 y2: ");
                scanf("%d%d%d%d",
                      &x1, &y1, &x2, &y2);

                setcolor(color);

                rectangle(x1, y1, x2, y2);
            }

            /* CIRCLE */
            else if (x1 >= 180 && x1 <= 260 &&
                     y1 >= 10 && y1 <= 40)
            {
                int radius;

                printf("Enter center x y: ");
                scanf("%d%d", &x1, &y1);

                printf("Enter radius: ");
                scanf("%d", &radius);

                setcolor(color);

                circle(x1, y1, radius);
            }

            /* FREEHAND */
            else if (x1 >= 270 && x1 <= 350 &&
                     y1 >= 10 && y1 <= 40)
            {
                setcolor(color);

                while (!kbhit())
                {
                    if (ismouseclick(WM_LBUTTONDOWN))
                    {
                        getmouseclick(
                            WM_LBUTTONDOWN,
                            x1,
                            y1
                        );

                        putpixel(x1, y1, color);
                    }

                    if (ismouseclick(WM_MOUSEMOVE))
                    {
                        getmouseclick(
                            WM_MOUSEMOVE,
                            x2,
                            y2
                        );

                        putpixel(x2, y2, color);
                    }
                }

                getch();
            }

            /* FLOOD FILL */
            else if (x1 >= 360 && x1 <= 440 &&
                     y1 >= 10 && y1 <= 40)
            {
                printf("Enter seed point x y: ");
                scanf("%d%d", &x1, &y1);

                setfillstyle(SOLID_FILL, color);

                floodfill(
                    x1,
                    y1,
                    getpixel(x1, y1)
                );
            }

            /* ERASER */
            else if (x1 >= 450 && x1 <= 530 &&
                     y1 >= 10 && y1 <= 40)
            {
                setcolor(BLACK);

                printf("Enter eraser position x y: ");
                scanf("%d%d", &x1, &y1);

                circle(x1, y1, 10);

                setfillstyle(SOLID_FILL, BLACK);

                floodfill(
                    x1,
                    y1,
                    BLACK
                );
            }

            /* CLEAR */
            else if (x1 >= 540 && x1 <= 620 &&
                     y1 >= 10 && y1 <= 40)
            {
                cleardevice();
                drawMenu();
            }
        }

        /* EXIT USING KEY */
        if (kbhit())
        {
            char ch = getch();

            if (ch == 'q' || ch == 'Q')
                break;
        }
    }

    closegraph();

    return 0;
}
