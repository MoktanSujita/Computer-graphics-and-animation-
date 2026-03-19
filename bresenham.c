//Implementation of Bresenham's Line Algorithm in C
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    struct Point p1, p2;

    printf("Enter starting point (x1 y1): ");
    scanf("%d %d", &p1.x, &p1.y);

    printf("Enter ending point (x2 y2): ");
    scanf("%d %d", &p2.x, &p2.y);

    int dx  = abs(p2.x - p1.x);
    int dy  = abs(p2.y - p1.y);
    int sx  = (p1.x < p2.x) ?  1 : -1;   // step direction in x
    int sy  = (p1.y < p2.y) ?  1 : -1;   // step direction in y
    int err = dx - dy;                     // initial error term

    while (1) {
        putpixel(p1.x, p1.y, WHITE);      // draw current pixel

        if (p1.x == p2.x && p1.y == p2.y) {
            break;                         // reached end point
        }

        int err2 = err * 2;

        if (err2 > -dy) {
            err  -= dy;
            p1.x += sx;                   // move in x direction
        }

        if (err2 < dx) {
            err  += dx;
            p1.y += sy;                   // move in y direction
        }
    }

    getch();          
    closegraph();     
    return 0;
}