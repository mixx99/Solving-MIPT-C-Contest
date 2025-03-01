#include <stdio.h>


int main()
{
	int n, d, r;
	scanf("%d%d", &n, &d);
	
	while(d != 0)
	{
		r = n % d;
		printf("%d ", (n-r)/d);
		n = d;
		d = r;
	}
}
