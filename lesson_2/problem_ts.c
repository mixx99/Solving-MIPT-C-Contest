#include <math.h>
#include <stdlib.h>

int double_area(struct triangle_t tr)
{
  int x1,x2,x3,y1,y2,y3;
  x1 = tr.pts[0].x;
  x2 = tr.pts[1].x;
  x3 = tr.pts[2].x;
  y1 = tr.pts[0].y;
  y2 = tr.pts[1].y;
  y3 = tr.pts[2].y;
  return abs((x1 * y2) + (x2 * y3) + (y1 * x3) - (y2 * x3) - (x2 * y1) - (y3 * x1));
}
