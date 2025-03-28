
// Compile with gcc problem_hwe.c -DNOCONTEST
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

#ifdef NOCONTEST
struct sieve_t;
struct sieve_t {
  int n;
  unsigned char *mod1;
  unsigned char *mod5;
};
#endif
void fill_sieve(struct sieve_t *sv);
int is_prime(struct sieve_t *sv, unsigned n);
void set_prime(struct sieve_t* sv, const unsigned n);
int is_prime_mod1(struct sieve_t* sv, const unsigned n);
int is_prime_mod5(struct sieve_t* sv, const unsigned n);
void fill_sieve(struct sieve_t* sv)
{
  int i, j;
  //assert(sv->n > 0 && sv->mod1 != NULL && sv->mod5 != NULL);
  int lim = 48 * (sv->n);
  sv->mod1[0] |= 1;
  for(i = 0; i*i < lim; i += 6) // something terribly wrong here with limit.
  {
    if(is_prime(sv, i + 1))
      for(j = (i+1)*(i+1); j <= lim; j += i + 1) 
        set_prime(sv, j); 
    if(is_prime(sv, i + 5))
      for(j = (i+5)*(i+5); j <= lim; j += i + 5)
        set_prime(sv, j);
  }
}

int is_prime(struct sieve_t* sv, const unsigned n)
{
  if(n == 3 || n == 2)
    return 1;
  if(n <= 1)
    return 0;
  if(n % 6 == 1)
    return !is_prime_mod1(sv, n);
  else if(n % 6 == 5)
    return !is_prime_mod5(sv, n);
  return 0;
}

int is_prime_mod5(struct sieve_t* sv, const unsigned n)
{
  int bitnum, bytenum, a;
  //assert(n - 5 < n);
  a = (n -  5) / 6;
  bytenum = a / CHAR_BIT;
  bitnum = a % CHAR_BIT;
  return (sv->mod5[bytenum] >> bitnum) & 1;
}

int is_prime_mod1(struct sieve_t* sv, const unsigned n)
{
  int bitnum, bytenum, a;
  //assert(n - 1 < n);
  a = (n - 1) / 6;
  bytenum = a / CHAR_BIT;
  bitnum = a % CHAR_BIT;
  return (sv->mod1[bytenum] >> bitnum) & 1;
}

void set_prime(struct sieve_t* sv, const unsigned n)
{
  int bytenum, bitnum, a;
  if(n <= 1 || n == 5) return;

  if(n % 6 == 1)
  {
    a = (n - 1) / 6;
    bytenum = a / CHAR_BIT;
    bitnum = a % CHAR_BIT;
    sv->mod1[bytenum] |= (1 << bitnum);
  }
  else if(n % 6 == 5)
  {
    a = (n - 5) / 6;
    bytenum = a / CHAR_BIT;
    bitnum = a % CHAR_BIT;
    sv->mod5[bytenum] |= (1 << bitnum);
  }
}
#ifdef NOCONTEST
int dump_prime_check(const int n);
void test(struct sieve_t* sv)
{
  int flag_result = 1;
  for(int i = 0; i < 1000; ++i)
    if(is_prime(sv, i) != dump_prime_check(i)){
      printf("Something wrond with %d\n", i);
      flag_result = 0;
      }
  if(flag_result)
    printf("All tests passed.\n");
  else
    printf("Something wrong.\n");
}

int dump_prime_check(const int n)
{
  if(n <= 1)
    return 0;
  int i;
  for(i = 2; i*i <= n; ++i)
    if(n % i == 0)
      return 0;
  return 1;
}
#endif
#ifdef NOCONTEST
int main()
{
  struct sieve_t sv;
  int i;
  sv.n = 10;
  sv.mod1 = calloc(sv.n, sizeof(char));
  sv.mod5 = calloc(sv.n, sizeof(char));
  fill_sieve(&sv);
  //test(&sv);
#ifdef NOCONTEST 
  int cnt = 1;
  for(i = 0; i < 100; ++i)
  {
    if(is_prime(&sv, i))
    {
      printf("%d - %d\n", cnt, i);
      cnt++;
    }
  }
  //printf("%d --- %d\n", sv.mod1[0], sv.mod5[0]);
#endif
}
#endif
