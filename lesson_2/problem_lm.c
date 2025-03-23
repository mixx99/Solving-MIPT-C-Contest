#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*
  Math insight: lcm(a,b) = ab / gcd(a, b) and lcm(a, b, c) = lcm(lcm(a, b), c)
*/

#define ULL unsigned long long

ULL gcd(ULL x, ULL y) 
{
  ULL q;
  if (y > x)
    return gcd(y, x);
  assert (y > 0);
  q = x % y;
  if (q == 0)
    return y;
  return gcd(y, q);
}

ULL lcm(ULL a, ULL b)
{
  return (a * b) / gcd(a, b);
}

ULL problem_lm(ULL d)
{
  ULL i, result = 2, tmp;
  for(i = 3; i <= d; ++i)
  {
    result = lcm(result, i);
  }
  return result;
}

int main()
{
  ULL a, res, result;
  res = scanf("%llu", &a);
  if(res != 1)
    abort();
  printf("%llu\n", problem_lm(a));
}
