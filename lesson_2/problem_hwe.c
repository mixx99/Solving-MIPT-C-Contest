#include <stdio.h>
#include <stdlib.h>

struct sieve_t;
void fill_sieve(struct sieve_t *sv);
int is_prime(struct sieve_t *sv, unsigned n);

struct sieve_t {
  int n;
  unsigned char *mod1;
  unsigned char *mod5;
};

void fill_sieve(struct sieve_t* sv)
{
  int i, j;
  assert(sv->n > 0 && sv->mod1 != NULL && sv->mod2 != NULL)
  for(i = 6; i < sv->n*8*6; i+=6)
    
}

int is_prime(struct sieve_t* sv, const unsgined n)
{
  if(n == 2 || n == 3 || n == 5)
    return 1;
  if(n == 4 || n == 6)
    return 0;
  if(n % 6 != 1 || n % 6 != 5)
    return 0;
  if(n % 6 == 1)
    return is_prime_mod1(sv, n);
  else if(n % 6 == 5)
    return is_prime_mod5(sv, n);
  assert(false); // TODO delete it
  return 0;
}

int is_prime_mod5(struct sieve_t* sv, const unsinged n)
{
  int bitnum, bytenum, a;
  a = (n + 1) / 6;
  bytenum = a / CHAR_BIT;
  bitnum = a % CHAR_BIT;
  return sv->mod5[bytenum] & (1 << bitnum); 
}

int is_prime_mod1(struct sieve_t* sv, const unsigned n)
{
  // Na =  a*6k + 1
  int bitnum, bytenum, a;
  a = (n - 1) / 6;
  bytenum = a / CHAR_BIT;
  bitnum = a % CHAR_BIT;
  return sv->mod1[bytenum] & (1 << bitnum);
}

void set_prime(struct sieve_t* sv, const unsigned n)
{

}

#if 1
int main()
{
  
}
#endif
