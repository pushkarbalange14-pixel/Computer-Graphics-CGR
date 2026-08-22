#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void main()
{
    int gd = DETECT, gm;
    int xc, yc, r, x, y, d;

    initgraph(&gd, &gm, "C://TC//BGI");

    printf("Enter xc, yc and radius: ");
    scanf("%d%d%d", &xc, &yc, &r);

    x = 0;
    y = r;
    d = 3 - (2 * r);
     putpixel(x,y,1);
    while (x <= y)
    {


	if (d < 0)
	{

	d= d + 4*x + 6 ;
	x=x+1;
	y=y;

	}
	else
	{
	d =d + 4 *(x-y) + 10;
	y=y-1;
	x=x+1;

	}
	putpixel(xc+x,yc+y,2);
	putpixel(xc+y,yc+x,2);
	putpixel(xc-x,yc+y,2);
	putpixel(xc-y,yc+x,2);

	putpixel(xc-x,yc-y,6);
	putpixel(xc-y,yc-x,6);
	putpixel(xc+y,yc-x,6);
	putpixel(xc+x,yc-y,6);

	}

	getch();
	closegraph();

	}
