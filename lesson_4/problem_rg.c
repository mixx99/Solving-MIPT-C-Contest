#include <stdio.h>
#include <stdlib.h>



// определяет длину петли в генераторе
unsigned cycle_len(generator_t gen);


unsigned cycle_len(generator_t gen)
{
  gen(); // 0
  int n = gen();
  int cnt = 1;
  while(1)
  {
    if(n == gen())
      return cnt;
    cnt++;
  }
}
