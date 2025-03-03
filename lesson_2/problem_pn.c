#include <stdio.h> 
#include <stdlib.h>

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

unsigned prime_number(unsigned n)
{
	if(n == 1)
		return 2;
	unsigned counter = 0, i = 2;
	while(1)
	{
		if(is_prime(i) == 1)
			counter++;
		if(counter == n)
			return i;
		i++;
	}
}



int main()
{
	unsigned n, check;
	check = scanf("%u", &n);
	if(check != 1)
		abort();
	printf("%u\n", prime_number(n));
	return 0;
}


