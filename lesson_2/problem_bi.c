#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void invert_bit(int n, unsigned char* arr, int bit)
{
	int idx = bit / 8;
	int btc = bit % CHAR_BIT;
				 
	if(((arr[idx] >> btc) & 1) == 1)
		arr[idx] = arr[idx] & (~(1u << btc));
	else
		arr[idx] = arr[idx] | (1u << btc);
}


void print_arr(int n, unsigned char* arr)
{
	for(int i = 0; i < n; ++i)
		printf("%hhu ", arr[i]);
	printf("\n");
}



int main()
{
	int n, bt, checkscnf, i;
	checkscnf = scanf("%d", &n);
	unsigned char* arr = calloc(n, CHAR_BIT);
	for(i = 0; i < n; ++i)
		checkscnf += scanf("%hhu", &arr[i]);
	checkscnf += scanf("%d", &bt);
	if(checkscnf != n + 2)
		abort();
	

	if(n * CHAR_BIT <= bt)
	{
		print_arr(n, arr);
		return 0;
	}

	invert_bit(n, arr, bt);
	print_arr(n, arr);
	return 0;
}
