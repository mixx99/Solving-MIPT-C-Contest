#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>


void fill_sieve(char* sv, int n);
void set_prime(char* sv, int size, int n);
int is_prime(char* sv, int size, int n);

void fill_sieve(char* sv, int n)
{
for(int i = 2; i*i < n; ++i)
  {
    if(is_prime(sv, n,i))
      for(int j = i * i; j < n; j += i)
          set_prime(sv, n,j);
  }
}

void set_prime(char* sv, int size, int n)
{
  assert(size > n);
  sv[n] = 1;
}

int is_prime(char* sv, int size, int n)
{
  assert(n < size);
  if(sv[n] == 0) return 1;
  else return 0;
}






int calc(char* s, int a, int b, int N)
{
  int n = 0;
  int res;
  while(1)
  {
  res = n*n + a*n + b;
  if(res < 0) 
    return n;
  if(s[res] == 1)
    return n;
  n++;
  }
}



int find_seq(char* s, int N)
{
  int a = -N + 1;
  int b = -N + 1;
  int i,j;
  int max = 0;
  int max_a = 0;
  int max_b = 0;
  int result;
  for(i = a; i < N; ++i)
    {
      for(j = b; j < N; ++j)
        {
          result = calc(s, i, j, N);
          if(result > max){
          //printf("res = %d, max = %d\n", result, max);
          max = result;
          max_a = i;
          max_b = j;
        }
    }
    }

  printf("%d %d %d\n", max_a, max_b, max);
}






int main()
{
  int N, check;
  check = scanf("%d", &N);
  if(check != 1)
    abort();
  char* s = calloc(N*N + N*N + N + 500, sizeof(char));
  fill_sieve(s, N*N + N*N + N + 500);
  find_seq(s, N);
}
