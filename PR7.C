#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void main()
{
    int gd = DETECT, gm;
    int x1,y1,x2,y2,x3,y3;
    int sx,sy;

    initgraph(&gd, &gm,"C://TC//BGI");

    printf("Enter coordinates of triangle:\n");
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

    printf("Enter sx and sy: ");
    scanf("%d%d",&sx,&sy);

    setcolor(GREEN);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);


    x1 = x1 * sx;
    y1 = y1 * sy;
    x2 = x2 * sx;
    y2 = y2 * sy;
    x3 = x3 * sx;
    y3 = y3 * sy;

    setcolor(MAGENTA);

    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    getch();
    closegraph();


}
