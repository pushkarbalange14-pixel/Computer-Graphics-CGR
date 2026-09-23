#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void main()
{
    int gd = DETECT, gm;
    int x1,y1,x2,y2;
    int tx,ty;

    initgraph(&gd, &gm,"C://TC//BGI");
    printf(" \n Enter co ordinates of rectangle ");
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

    printf("\n Enter tx and ty :");
    scanf("%d%d",&tx,&ty);

    setcolor(CYAN);
    rectangle(x1,y1,x2,y2);

    setcolor(YELLOW);
    rectangle(x1+tx,y1+ty,x2+tx,y2+ty);

    getch();
    closegraph();

    }

