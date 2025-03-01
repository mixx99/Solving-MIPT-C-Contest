#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


#if 0
unsigned long long gcd(unsigned long long x, 
                       unsigned long long y) {
  unsigned long long q;
  if (y > x)
    return gcd(y, x);
  assert (y > 0);
  q = x % y;
  if (q == 0)
    return y;
  return gcd(y, q);
}
#endif

int main() {
  long long x = 0, y = 0, g;
  int res;
  long long result = 0;
  res = scanf("%lld %lld", &x, &y);
  assert(res == 2);
  x = abs(x);
  y = abs(y);
  while(1)
  {
	long long q;
	if(y > x)
	{
		long long temp = y;
		y = x;
		x = temp;
		continue;
	}
	assert(y > 0);
	q = x % y;
	if(q == 0)
	{
		result = y;
		break;
	}
	x = y;
	y = q;

  }
  printf("%lld\n", result);
  return 0;
}
