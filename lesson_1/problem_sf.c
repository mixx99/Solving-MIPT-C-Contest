#include <stdio.h>
#include <stdlib.h>


void full_sieve(long long* sieve, int n)
{
  int i;
  sieve[0] = 1;
  sieve[1] = 2;
  for(i = 2; i < n; ++i)
  {
    sieve[i] = sieve[i-1] + sieve[i-2];
  }
}

void problem_sf(long long* sieve, int s, int n)
{
  int flag = 0, i;
  for(i = s - 1; i >= 0; --i)
  {
    if(sieve[i] <= n)
    {
      flag = 1;
      n -= sieve[i];
      printf("%d", 1);
      continue;
    }
    if(flag == 1)
      printf("%d", 0);
  }
}


int main()
{
  int n, res;
  res = scanf("%d", &n);
  if(res != 1)
    abort();
  long long* sieve;
  int s = 50;
  sieve = calloc(s, sizeof(long long));
  full_sieve(sieve, s);
  problem_sf(sieve, s, n);
}
