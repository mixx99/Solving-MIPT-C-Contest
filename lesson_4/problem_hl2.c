#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#if 0
struct node_t {
  struct node_t *next;
  int data;
};
#endif

// определяет длину петли в односвязном списке
// возвращает длину если есть, 0 если петли нет
int loop_len(struct node_t *top);



int loop_len(struct node_t* top)
{
  int flag = 0, counter = 0;
  if(top == NULL) return 0;
  if(top->next == NULL) return 0;
  struct node_t *turtle = top;
  struct node_t *rabbit = top;
  while(1)
  {
    if((rabbit->next) == NULL || (rabbit->next->next) == NULL)
      break;
    rabbit = rabbit->next->next;
    turtle = turtle->next;
    if(turtle == rabbit)
    {
      flag = 1;
      break;
    }
  }
  if(flag == 0)
    return 0;
  assert(rabbit == turtle);
  while(1)
  {
    rabbit = rabbit->next;
    counter++;
    if(rabbit == turtle)
      return counter;
  }
  
}

