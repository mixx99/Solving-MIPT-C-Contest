#include <stdlib.h>
#include <stdio.h>


void print_maxmin(const int* s, int n)
{
  int max = 0;
  int min = s[0];
  int i = 0;
  if(n == 0)
    printf("%d %d\n", 0,0);
  if(n == 1)
    printf("%d %d\n", s[0], s[0]);
  for(i = 0;i < n; ++i)
  {
    if(s[i] > max)
      max = s[i];
    if(s[i] < min)
      min = s[i];
  }
  printf("%d %d\n", min, max);

}





int main()
{
  int n;
  int* s;
  int i = 0;
  scanf("%d", &n);
  s = calloc(n, sizeof(int));
  for(i = 0; i < n; ++i)
    scanf("%d", &s[i]);
  print_maxmin(s, n);
}
