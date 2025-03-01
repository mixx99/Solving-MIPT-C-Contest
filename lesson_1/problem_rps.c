#include <stdio.h>


unsigned pow_mod(unsigned n, unsigned k, unsigned m)
{
	unsigned mult = n % m;
	unsigned prod = 1;
	while(k > 0)
	{
		if(k % 2 == 1) 
		{ 
			prod = (prod * mult) % m; 
			k = k - 1; 
		}
		mult = (mult * mult) % m;
		k = k / 2;
	}
	return prod;
}

unsigned spow_mod(unsigned a, unsigned b, unsigned c)
{
	unsigned ans = a;
	while(b > 1)
	{
		ans = pow_mod(ans, a, c);
		b--;
	}
	return ans % c;
}


int main()
{
	unsigned a,b,n;
	scanf("%d%d%d", &a, &b, &n);
	printf("%d", spow_mod(a,b,n));
}
