#include <stdio.h>


// определяет есть ли петля в односвязном списке
// возвращает 0 если нет и 1 если есть
int list_is_a_loop(struct node_t *top)
{
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
      return 1;
  }
  return 0;
}
