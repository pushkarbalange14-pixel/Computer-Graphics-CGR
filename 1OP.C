#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    setcolor(6);

    rectangle(145, 145, 270, 270);
    circle(208, 208, 56);

    line(178, 145, 237, 145);
    line(178, 145, 208, 95);
    line(237, 145, 208, 95);

    line(178, 270, 237, 270);
    line(178, 270, 208, 320);
    line(237, 270, 208, 320);

    line(145, 177, 145, 233);
    line(145, 177, 95, 205);
    line(145, 233, 95, 205);

    line(270, 177, 270, 233);
    line(270, 177, 321, 205);
    line(270, 233, 321, 205);

    line(145, 145, 175, 145);
    line(145, 145, 145, 175);
    line(145, 145, 115, 115);

    line(240, 145, 270, 145);
    line(270, 145, 270, 175);
    line(270, 145, 300, 115);

    line(145, 240, 145, 270);
    line(145, 270, 175, 270);
    line(145, 270, 115, 300);

    line(240, 270, 270, 270);
    line(270, 240, 270, 270);
    line(270, 270, 300, 300);

    getch();
    closegraph();
}