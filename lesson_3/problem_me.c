#ifdef NOCONTEST
#include <stdio.h>
#include <stdlib.h>
#endif

int compare_ints(const void* a, const void* b)
{
  const int *a1 = a;
  const int *b1 = b;
  if(*a1 > *b1) return 1;
  if(*b1 > *a1) return -1;
  return 0;
}

int majority_element(const int *parr, int len)
{
  int *arr, i, counter = 0, result;
  arr = calloc(len, sizeof(int));
  for(i = 0; i < len; ++i)
    arr[i] = parr[i];
  qsort(arr, len, sizeof(int), compare_ints);
  result = arr[0];

  for(i = 0; i < len; ++i)
  {
    if(result != arr[i])
    {
      result = arr[i];
      counter = 1;
    }
    else if(result == arr[i])
      counter++;

    if(counter >= len / 2 + 1)
    {
      free(arr);
      return result;
    }
  }
  free(arr);
  return -1;
}


#ifdef NOCONTEST
int main()
{
  int* arr;
  int n, i;
  scanf("%d", &n);
  arr = calloc(n, sizeof(int));
  for(i = 0; i < n; ++i)
    scanf("%d", &arr[i]);
  printf("%d", majority_element(arr, n));
  free(arr);
}
#endif
