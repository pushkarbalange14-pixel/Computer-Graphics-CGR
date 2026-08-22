#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include<stdlib.h>

void main()
{
    int gd = DETECT, gm;
    int x1, x2, y1, y2;
    int dx,dy;
    int x,y,p;

    clrscr();

    initgraph(&gd, &gm, "C:\\TC\\BGI");
    printf(" Enter x1 and y1\n");
    scanf("%d %d",&x1,&y1);
    printf(" Enter x2 and y2\n");
    scanf("%d %d",&x2,&y2);

    dx=x2-x1;
    dy=y2-y1;

    x=x1;
    y=y1;
    putpixel(x,y,WHITE);


    p=2*dy-dx;
    while(x<x2)
    {
     x++;
     if(p<0)
     {

     p=p+2*dy;

     }
      else
      {
      y++;
      p=p+2*dy-2*dx;
      }

      putpixel(x,y,WHITE);


      }

      getch();
      closegraph();

      }



