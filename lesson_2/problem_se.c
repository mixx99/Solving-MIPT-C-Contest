#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>


struct sieve_t
{
	unsigned size;
	char* mass;
};

unsigned long long sieve_upper_bound(unsigned n)
{
	if(n <= 20)
		return 500;
	double dnum = n;
	double dres = dnum * (log(dnum) + log(log(dnum)));
	return (unsigned long long) round(dres);
}

void free_sieve(struct sieve_t* t)
{
	free(t->mass);
	t->mass = 0;
	t->size = 0;
}

unsigned is_prime(unsigned n)
{
        if(n < 2)
        	return 0;
        unsigned int i;
        for(i = 2; i*i <= n; ++i)
        {
                if((n % i) == 0)
                       return 0;
        }
        return 1;

}

void mark_num_in_arr(char* t, unsigned start, unsigned end, unsigned n)
{
	for(int i = start + n; i < end; i += n)
	{
		t[i] = 1;
	}
}

unsigned long long find_prime_numbers(struct sieve_t* t, unsigned n)
{
	unsigned counter = 0;
	
	for(int i = 2; i < t->size - 1; ++i)
	{
		if(t->mass[i] == 0)
		{
			if(is_prime(i) == 1)
			{
				counter++;
				mark_num_in_arr(t->mass, i, t->size, i);
			}
			else
				t->mass[i] = 1;
			if(i > n) return counter - 1;
		}
	}
	return counter;
}


int main()
{
	unsigned n, check;
	check = scanf("%u", &n);
	if(check != 1)
		abort();
	struct sieve_t t;
	t.size = sieve_upper_bound(n);
	t.mass = calloc(t.size, sizeof(char));

	printf("%llu\n", find_prime_numbers(&t, n));
	
	free_sieve(&t);
	return 0;
}
