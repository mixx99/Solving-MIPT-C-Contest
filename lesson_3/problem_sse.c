#include <stdlib.h>
#include <stdio.h>


int i_min(int* s, int n, int start)
{
  int min = s[start];
  int idx = start;
  for(int i = start; i < n; ++i)
  {
    if(s[i] < min)
    {
      min = s[i];
      idx = i;
    }
  }
  return idx;
}

void sel_sort(int* s, int n, int end)
{
  int i, index_min;

  for(i = 0; i <= end; ++i)
  {
    index_min = i_min(s,n,i);
    int tmp = s[i];
    s[i] = s[index_min];
    s[index_min] = tmp;
  }
}




int main()
{
  int n, i, end;
  int *s;
  scanf("%d", &n);
  s = calloc(n, sizeof(int));
  for(i = 0; i < n; ++i)
    scanf("%d", &s[i]);
  scanf("%d", &end);
  sel_sort(s, n, end);  
  for(i = 0; i < n; ++i)
    printf("%d ", s[i]);
  printf("\n");
}
