#include <stdlib.h>
#include <stdio.h>



int find_lower_bit(int n)
{
	int counter = 0;
	while(n != 0 && (++counter))
		if((n & 1) == 1)
			return counter - 1;
		else n = n >> 1;
}

int find_higher_bit(int n)
{
	int counter = 0;
	int result = 0;
	while(n != 0)
	{
		if((n & 1) == 1) 
			result = counter;
		counter++;
		n = n >> 1;
	}
	return result;
}


int main()
{
	int a, check;
	check = scanf("%d", &a);
	if(check != 1)
		abort();
	if(a == 0)
	{
		printf("NO\n");
			return 0; }
	printf("%d %d\n", find_higher_bit(a), find_lower_bit(a));


}
