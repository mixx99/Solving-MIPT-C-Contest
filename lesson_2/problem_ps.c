#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
void fill_sieve(struct sieve_t *sv);
int nth_prime(struct sieve_t *sv, int N);
int is_prime(struct sieve_t* sv, int N);
void set_prime(struct sieve_t* sv, int N);




int nth_prime(struct sieve_t* sv, int N)
{
  int cnt = 0, i = 2;
  if(N == 1) return 2;

  while(1)
  {
    if(is_prime(sv, i) == 1)
      cnt++;
    if(cnt == N)
      return i;
    i++;
  }
}


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
