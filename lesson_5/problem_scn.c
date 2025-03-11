#include <stdio.h>

int main() {
  char str[1025] = {'\0'}; 
  int i, n = 0;
  for(i = 0; i < 1025; ++i)
    scanf("%c", &str[i]);
  for(i = 0; i < 1025; ++i)
    n += str[i];
  printf("%d\n", n + 10);
}

