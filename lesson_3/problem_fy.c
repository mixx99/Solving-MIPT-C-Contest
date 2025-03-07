#include <stdio.h>
#include <stdlib.h>

int myrand() {
  static unsigned long int seed = 1;
  seed = seed * 1103515245 + 12345;
  return (unsigned int)(seed / 65536) % 32768;
}

void shuffle_arr(int* s, int n)
{
  int sizearr = n, number, temp;
  if(n == 0)
  {
    printf("%d\n", 0);
    return;
  }
  if(n == 1)
  {
    return;
  }

  for(;;)
  {
    number = myrand() % (sizearr);
    temp = s[sizearr - 1];
    s[sizearr - 1] = s[number];
    s[number] = temp;
    sizearr--;
    if(sizearr == 0) return;
  }
}


int main()
{
  int n, i;
  int* s;
  scanf("%d", &n);
  s = calloc(n, sizeof(int));
  for(i = 0; i < n; ++i)
    scanf("%d", &s[i]);
  shuffle_arr(s, n);
  for(i = 0; i < n; ++i)
    printf("%d ", s[i]); 
}
