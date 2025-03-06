#include "u_template.h"
void fill_sieve(struct sieve_t *sv);
int is_prime(struct sieve_t *sv, unsigned n);

void set_prime(struct sieve_t *sv, unsigned int n)
{
        unsigned int num = n / 8;
        unsigned int bitnum = n % 8;
        sv->s[num] = sv->s[num] | (1 << bitnum);
}


int is_prime(struct sieve_t *sv, unsigned int n)
{
        unsigned int num = n / 8;
        unsigned int bitnum = n % 8;
		int x = ((sv->s[num]) >> bitnum) & 1;
        return (x == 0) ? 1 : 0;
}



void fill_sieve(struct sieve_t *sv)
{
        for(unsigned int i = 2; i*i < sv->n * 8; ++i)
                if(is_prime(sv, i))
                        for(unsigned int j = i * i; j < sv->n * 8; j += i)
                                set_prime(sv, j);
}
