
#if 1
#include <stdio.h>

int foo(int x, int y);

int main() {
  int x = 0, y = 0, z = 0;
  scanf("%d%d", &x, &y);
  z = foo(x, y);
  printf("%d\n", z);
}

#endif

int foo(int a, int b)
{
  int edi = a;
  int esi = b;
  int eax = edi;
  eax *= edi;
  eax *= edi;
  if(eax < 0)
    goto l4;
  return eax;

  l4:
    esi *= esi;
    edi += edi;
    int edx = 17;
    edx -= edi;
    edx -= esi;
    eax += edx;
    return eax;
}
