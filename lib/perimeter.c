#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct _point {
  float x;
  float y;
};

typedef struct _point point;

// subtract points is subtraction per component
// (x1, y1) - (x2, y2) == (x1-x2, y1-y2)
point p_sub(const point a, const point b) {
  point res = { a.x - b.x, a.y - b.y };
  return res;
}

// square root of the sum of squares
//  ___________
// V x^2 + y^2
float p_abs(const point a) {
  return sqrtf( (a.x * a.x) + (a.y * a.y) );
}

// sum of distance between points
// last point refers back to the first
//  _______________________
// V (x1-x2)^2 + (y1-y2)^2
//
// example: 4 points should be a quadrilateral
float perimeter(const int n, const point points[]) {
  float peri = 0.0;

  for (int i=0; i<n; ++i) {
    peri += p_abs( p_sub(points[i], points[(i+1)%n]) );
  }

  return peri;
}


int main(void) {
  float solution = 0.0;
  point points[] = { {0.1, 0.2}, {0.3, 0.5} } ;

  solution = perimeter(2, points);
  printf("%f\n", solution);

  return EXIT_SUCCESS;
}
