#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void flood(int x ,int y, int o, int n)
{
if( getpixel(x,y) == o)
{
  putpixel(x,y,n);
  delay(8);
  flood(x+1,y,o,n+2);
  flood(x-1,y,o,n+1);
  flood(x,y+1,o,n+3);
  flood(x,y-1,o,n+4);
  flood(x-1,y-1,o,n+5);
  flood(x+1,y-1,o,n+6);
  flood(x-1,y+1,o,n+7);
  flood(x+1,y+1,o,n+8);
 }
}
void main()
{
    int gd = DETECT, gm;
    int x=51;
    int y=51;
    int n=12;
    int o=0;
    initgraph(&gd, &gm, "C://TC//BGI");
    rectangle(50,50,110,110);




     flood(x,y,o,n);
     getch();
     closegraph();

 }

