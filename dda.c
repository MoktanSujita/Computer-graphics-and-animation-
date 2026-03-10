#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void dda_line(int x1, int x2, int y1, int y2)
{
  int dx = x2 - x1;
  int dy = y2 - y1;

  int steps = (abs(dx)> abs(dy))? abs(dx) : abs(dy);
  float x_inc = (float) dx/steps;
  float y_inc = (float) dy/steps;

  float x = x1;
  float y = y1;
  printf("Points on the line::\n");
  printf("Step\t x\t y\t");
  printf("........\t............\t..........\t");
  for(int i =0; i <= steps; i++)
  {
    printf("%d\t %d\t %d\n ", i, (int) round(x), (int) round(y));
    x+= x_inc;
    y+=y_inc;
  }
}

int main()
{
    int x1,y1,x2,y2;
    printf("Enter the starting points::");
    scanf("%d %d", &x1, &y1);

    printf("Enter the ending point:");
    scanf("%d %d", &x2,&y2);

    dda_line(x1, x2, y1, y2);
    return 0;
}
