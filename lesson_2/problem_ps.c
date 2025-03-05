// It doesn't pass the test #11, Time-Limit. I'll fix it later


#include <stdlib.h>
#include <stdio.h>
#include "u_template.h"
void fill_sieve(struct sieve_t *sv);
int nth_prime(struct sieve_t *sv, int N);
int is_prime(int n);
void mark_num_in_arr(char* t, int start, int end, int n);



void fill_sieve(struct sieve_t* sv)
{
	for(int i = 2; i < sv->n; ++i)
	{
		if(sv->s[i] == 0)
		{
			if(is_prime(i) == 1){
				mark_num_in_arr(sv->s, i, sv->n, i);
			}
			else
				sv->s[i] = 1;
		}	
	}
}

int is_prime(int n)
{
        if(n < 2)
        	return 0;
        for(unsigned int i = 2; i*i <= n; ++i)
        {
                if((n % i) == 0)
                       return 0;
        }
        return 1;

}

int nth_prime(struct sieve_t* sv, int N)
{
	int counter = 0;
	for(int i = 2; i < sv->n; ++i)
	{
		if(sv->s[i] == 0)
			counter++;
		if(counter == N)
			return i;
	}
	return N;
}

void mark_num_in_arr(char* t, int start, int end, int n)
{
	for(int i = start + n; i < end; i += n)
	{
		t[i] = 1;
	}
}
