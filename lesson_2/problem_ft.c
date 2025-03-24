#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ULL unsigned long long


ULL pow_mod(ULL n, ULL k, ULL m)
{
  ULL mult = n % m;
  ULL prod = 1;
  while(k > 0)
  {
    if((k % 2) == 1)
    {
      prod = (prod * mult) % m; 
      k = k - 1; 
    }
    mult = (mult * mult) % m;
    k = k / 2;
  }
  return prod;
}

int problem_ft(const int a)
{
  int cnt = 0;
  while(cnt < 100)
  {
    ULL b = rand();
    if(pow_mod(b, a-1, a) != 1 && b % a != 0)
      return 0;
    cnt++;
  }
  return 1;
}

int main()
{
  ULL a;
  scanf("%llu", &a);
  srand(time(NULL));
  printf("%d\n", problem_ft(a));
}
