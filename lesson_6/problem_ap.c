#include <stdio.h>
#include <stdlib.h>

/*
loop:
  mov eax, edi
  xor edx, edx
  div ecx
  test edx, edx
  je composite

  add ecx, 2
  mov eax, ecx
  imul eax, eax
  cmp eax, edi
  jbe loop

  jmp prime


*/





int foo(int a)
{
  int i;
  for(i = 2; i < a; ++ i)
  {
    if(a % i == 0)
      return 0;
  }
  return 1;
}









int main()
{
  int a;
  scanf("%d", &a);
  printf("%d\n",foo(a));
}
