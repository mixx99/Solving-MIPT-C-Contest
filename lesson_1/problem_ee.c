#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

long long gcd(long long x, long long y)
{
  while(y != 0)
  {
    long long temp = y;
    y = x % y;
    x = temp;
  }
  return llabs(x);
}

long long extended_gcd(long long x, long long y, long long* a, long long* b)
{
  if(y == 0)
  {
    *a = 1;
    *b = 0;
    return x;
  }
  long long a1, b1;
  long long d = extended_gcd(y, x % y, &a1, &b1);
  *a = b1;
  *b = a1 - (x / y) * b1;

  return d;
}


int main()
{
  long long x,y,d, a, b;
  int res = 0;
  res = scanf("%lld%lld", &x, &y);
  if(res != 2)
    abort();
  
  d = extended_gcd(x, y, &a, &b);
  if(d < 0)
  {
    d = -d;
    a = -a;
    b = -b;
  }
  printf("%lld %lld %lld\n", a, b, d);
}
