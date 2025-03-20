#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct sieve_t;
void fill_sieve(struct sieve_t* sv);
void set_prime(struct sieve_t* sv, int N);
int is_prime(struct sieve_t* sv, int N);
int is_simp_and_circ(const int N, struct sieve_t* sv);
struct sieve_t {
  int n;
  char *s;
};

void fill_sieve(struct sieve_t* sv)
{
for(int i = 2; i*i < sv->n; ++i)
  {
    if(is_prime(sv, i))
      for(int j = i * i; j < sv->n; j += i)
          set_prime(sv, j);
  }
}

void set_prime(struct sieve_t* sv, int N)
{
  assert(sv->n > N);
  sv->s[N] = 1;
}

int is_prime(struct sieve_t* sv, int N)
{
  assert(N < sv->n);
  if(sv->s[N] == 0) return 1;
  else return 0;
}

int problem_cc(struct sieve_t* sv, const int N)
{
  int i;
  int lresult = 0, rresult = 0;
  for(i = N; i > 0; --i)
  {
    if(is_simp_and_circ(i, sv) == 1)
    {
      lresult = i;
      break;
    }
  }
  for(int i = N;i < 1000000; ++i)
  {
    if(is_simp_and_circ(i, sv) == 1)
    {
      rresult = i;
      break;
    }
  }
  if(abs(N - lresult) > abs(rresult - N))
    return rresult;
  else
    return lresult;
}

int is_simp_and_circ(const int N, struct sieve_t* sv)
{
  if(N == 1 || N == 2 || N == 3 || N == 5 || N == 7)
    return 1;
  if(N < 10)
    return 0;
  if(N % 10 == 0)
    return 0;
  long long m, result = N;
  if(N < 10) m = 1;
  else if(N < 100) m = 100;
  else if(N < 1000) m = 1000;
  else if(N < 10000) m = 10000;
  else if(N < 100000) m = 1000000;
  else if(N < 1000000) m = 1000000; 
  while(1)
  {
    result += (result % 10) * m;
    result /= 10;
    if(sv->s[result] == 1)
      return 0;
    if(result == N)
      return 1;
  }
}

int main()
{
  int d, res;
  res = scanf("%d", &d);
  if(res != 1)
    abort();
  struct sieve_t sieve;
  sieve.n = d * 10;
  sieve.s = calloc(sieve.n, sizeof(char));
  fill_sieve(&sieve);
  printf("%d\n", problem_cc(&sieve, d));
}



