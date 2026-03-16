#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
};

struct Line {
    struct Point start;
    struct Point end;
    int steps;
    float x_inc;
    float y_inc;
};

struct Line init_line(struct Point start, struct Point end) {
    struct Line line;
    line.start = start;
    line.end = end;

    int dx = end.x - start.x;
    int dy = end.y - start.y;

    // Calculate steps and increments
    line.steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    line.x_inc = (float)dx / line.steps;
    line.y_inc = (float)dy / line.steps;

    return line;
}

void draw_line(struct Line line) {
    float x = line.start.x;
    float y = line.start.y;

    for (int i = 0; i <= line.steps; i++) {
        // Use CYAN for a cleaner look on Mint
        putpixel((int)round(x), (int)round(y), BLUE);
        x += line.x_inc;
        y += line.y_inc;
    }
}

int main() {
    int gd = DETECT, gm;
    
    
    initgraph(&gd, &gm, "");

    struct Point p1, p2;

    printf("Enter starting point (x1 y1): ");
    if (scanf("%d %d", &p1.x, &p1.y) != 2) return 1;

    printf("Enter ending point (x2 y2): ");
    if (scanf("%d %d", &p2.x, &p2.y) != 2) return 1;

    struct Line line = init_line(p1, p2);
    draw_line(line);

    getch();
    closegraph();
    return 0;
}