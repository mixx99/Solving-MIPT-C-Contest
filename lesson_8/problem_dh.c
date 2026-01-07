#include <assert.h>
#include <math.h>
#include <stdio.h>

double f(double a, double b, double c, double x) {
  return a * x * x * sin(x) + b * x * cos(x) + c;
}

int main() {
  double a, b, c, n, x1, x2, mid;
  double epsilon = 1e-6;
  int check;
  check = scanf("%lf%lf%lf%lf", &a, &b, &c, &n);
  assert(check == 4);

  x1 = -n;
  x2 = n;
  mid = (x1 + x2) / 2;
  while (fabs(x2 - x1) > epsilon) {
    if (fabs(f(a, b, c, mid)) < epsilon)
      break;
    if (f(a, b, c, mid) * f(a, b, c, x1) <= 0)
      x2 = mid;
    else if(f(a,b,c,mid) * f(a,b,c,x2) <= 0)
      x1 = mid;
    else{
      mid = 0;
      break;
    }
    mid = (x1 + x2) / 2;
  }
  if(fabs(mid) < epsilon)
    printf("%.1lf\n", mid);
  else printf("%.5lf\n", mid);
}
