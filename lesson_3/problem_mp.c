#include <stdio.h>
#include <stdlib.h>

struct polynom
{
  int a, x;
};

struct polynom* mult(struct polynom* arr1, const int n, struct polynom* arr2, const int m)
{
  int i, j;
  struct polynom* arr3;
  arr3 = calloc(n + m - 1, sizeof(struct polynom)); 
  for(i = 0; i < n; ++i)
  {
    for(j = 0; j < m; ++j)
      {
        arr3[arr1[i].x + arr2[j].x].a += arr1[i].a * arr2[j].a;
      }
  }

  return arr3;
}


int main()
{
  int n, m, res, i, real_size;
  struct polynom *arr1, *arr2, *arr3;
  res = scanf("%d%d", &n, &m);
  arr1 = calloc(n, sizeof(struct polynom));
  arr2 = calloc(m, sizeof(struct polynom));
  if(res != 2)
    abort();
  for(i = 0; i < n; ++i)
  {
    scanf("%d", &arr1[i].a);
    arr1[i].x = i;
  }
  for(i = 0; i < m; ++i)
  {
    scanf("%d", &arr2[i].a);
    arr2[i].x = i;
  }
  arr3 = mult(arr1, n, arr2, m);

  for(i = 0; i < n + m - 1; ++i)
    if(arr3[i].a != 0) real_size = i;

  for(i = 0; i <= real_size; ++i)
    printf("%d ", arr3[i].a);
  free(arr1); free(arr2); free(arr3);
}
