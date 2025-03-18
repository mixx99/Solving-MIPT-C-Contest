#include <stdio.h>
#include <stdlib.h>

int fact(int n);
void problem_fs(int n);
int find_elder_cf(const int n);

int fact(int n)
{
  int result = 1, i;
  for(i = 1; i <= n; ++i)
    result *= i;
  return result;
}

void problem_fs(int n)
{
  int eld_coef = find_elder_cf(n), i, cf;
  for(i = eld_coef; i > 0; --i)
  {
    cf = n / fact(i);
    printf("%d.", cf);
    n -= fact(i) * cf;
  }
}

int find_elder_cf(const int n)
{
  int i, c = 1;
  for(i = 0; i <= n; ++i, ++c)
  {
    if(fact(c) > n)
      return c - 1;
  }
}

int main()
{
  int n, res;
  res = scanf("%d", &n);
  if(res != 1)
    abort();
  problem_fs(n);
}
