#include <stdio.h>


unsigned long long fib(unsigned long long n)
{
	if(n == 0)
		return 0ull;
	unsigned long long first = 0ull, second = 1ull;
	int i;
	for(i = 2; i <= n; i++)
	{
		unsigned long long tmp = second;
		second = second + first;
		first = tmp;
	}
	return second;
}

int main()
{
	unsigned long long n, m;
	scanf("%llu%llu", &n, &m);
	int i = 3;
	while(1)
	{
		if((fib(i) % m == 0) && (fib(i + 1) % m) == 1){
			break;
		}
		++i;
	}
	printf("%llu\n", fib((n % i)) % m);
}
