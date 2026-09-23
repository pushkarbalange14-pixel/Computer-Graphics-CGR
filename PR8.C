#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void main()
{
    int gd = DETECT, gm;

    float x1, y1, x2, y2, x3, y3;
    float an, r;
    float a1, b1, a2, b2, a3, b3;

    clrscr();

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    printf("Enter coordinates of triangle:\n");

    printf("Enter x1 y1 x2 y2 x3 y3: ");
    scanf("%f%f%f%f%f%f",&x1, &y1, &x2, &y2, &x3, &y3);



    printf("Enter angle of rotation: ");
    scanf("%f", &an);

    r = an * 3.14159/180;


    a1 = x1;
    b1 = y1;

    a2 = x1 + (x2 - x1) * cos(r) - (y2 - y1) * sin(r);
    b2 = y1 + (x2 - x1) * sin(r) + (y2 - y1) * cos(r);
    a3 = x1 + (x3 - x1) * cos(r) - (y3 - y1) * sin(r);
    b3 = y1 + (x3 - x1) * sin(r) + (y3 - y1) * cos(r);



    setcolor(WHITE);

    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);


    setcolor(RED);

    line(a1, b1, a2, b2);
    line(a2, b2, a3, b3);
    line(a3, b3, a1, b1);

    getch();
    closegraph();
}