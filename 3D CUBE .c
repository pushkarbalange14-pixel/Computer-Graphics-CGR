#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

#define PI 3.14159265

typedef struct
{
    float x, y, z;
} Point3D;

void project(Point3D p, int *x, int *y)
{
    float scale = 1.0 / (p.z + 5);

    *x = 320 + (int)(p.x * 120 * scale);
    *y = 240 - (int)(p.y * 120 * scale);
}

void drawCube(Point3D p[])
{
    int x[8], y[8];
    int i;

    for(i = 0; i < 8; i++)
        project(p[i], &x[i], &y[i]);

    /* Front face */
    line(x[0],y[0],x[1],y[1]);
    line(x[1],y[1],x[2],y[2]);
    line(x[2],y[2],x[3],y[3]);
    line(x[3],y[3],x[0],y[0]);

    /* Back face */
    line(x[4],y[4],x[5],y[5]);
    line(x[5],y[5],x[6],y[6]);
    line(x[6],y[6],x[7],y[7]);
    line(x[7],y[7],x[4],y[4]);

    /* Connecting edges */
    line(x[0],y[0],x[4],y[4]);
    line(x[1],y[1],x[5],y[5]);
    line(x[2],y[2],x[6],y[6]);
    line(x[3],y[3],x[7],y[7]);
}

void translate(Point3D p[], int n, float tx, float ty, float tz)
{
    int i;

    for(i = 0; i < n; i++)
    {
        p[i].x += tx;
        p[i].y += ty;
        p[i].z += tz;
    }
}

void scale(Point3D p[], int n, float sx, float sy, float sz)
{
    int i;

    for(i = 0; i < n; i++)
    {
        p[i].x *= sx;
        p[i].y *= sy;
        p[i].z *= sz;
    }
}

void rotateZ(Point3D p[], int n, float angle)
{
    int i;
    float rad;
    float x, y;

    rad = angle * PI / 180;

    for(i = 0; i < n; i++)
    {
        x = p[i].x;
        y = p[i].y;

        p[i].x = x * cos(rad) - y * sin(rad);
        p[i].y = x * sin(rad) + y * cos(rad);
    }
}

void main()
{
    int gd = DETECT, gm;
    int choice;
    float angle;

    Point3D cube[8] =
    {
        {-1,-1,-1},
        { 1,-1,-1},
        { 1, 1,-1},
        {-1, 1,-1},

        {-1,-1, 1},
        { 1,-1, 1},
        { 1, 1, 1},
        {-1, 1, 1}
    };

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    printf("\n3D CUBE TRANSFORMATION");
    printf("\n1. Translation");
    printf("\n2. Scaling");
    printf("\n3. Rotation about Z-axis");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    cleardevice();

    outtextxy(250, 30, "Original Cube");
    drawCube(cube);

    getch();
    cleardevice();

    if(choice == 1)
    {
        translate(cube, 8, 1, 1, 0);
        outtextxy(230, 30, "Translated Cube");
    }
    else if(choice == 2)
    {
        scale(cube, 8, 1.5, 1.5, 1.5);
        outtextxy(230, 30, "Scaled Cube");
    }
    else if(choice == 3)
    {
        printf("\nEnter rotation angle: ");
        scanf("%f", &angle);

        rotateZ(cube, 8, angle);

        outtextxy(230, 30, "Rotated Cube");
    }
    else
    {
        printf("Invalid choice");
        closegraph();
        return;
    }

    drawCube(cube);

    getch();
    closegraph();
}
