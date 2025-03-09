#include <stdio.h>
#include <stdlib.h>
#if 0
struct node_t {
  struct node_t *next;
  int data;
};
#endif
// считывает список из входного файла, так, чтобы все чётные числа были в начале
struct node_t *read_list(FILE *inp);

// удаляет список элемент за элементом
void delete_list(struct node_t *top);


struct node_t *read_list(FILE *inp)
{
  int n, res;
  struct node_t* l1 = NULL;
  struct node_t* l2 = NULL;// = calloc(1, sizeof(struct node_t)); // odd

  struct node_t* newnode;
  struct node_t* last1 = l1;
  struct node_t* last2 = l2;


  while(1)
  {
    res = fscanf(inp, "%d", &n);
    if(res == EOF)
      break;
    newnode = calloc(1, sizeof(struct node_t));
    newnode->data = n;
    newnode->next = NULL;

    if(n % 2 == 0)
    {
      if(l1 == NULL)
      {
        l1 = newnode;
        last1 = l1;
      }
      else
      {
        last1->next = newnode;
        last1 = newnode;
      }
    }
    else
    {
      if(l2 == NULL)
      {
        l2 = newnode;
        last2 = l2;
      }
      else
      {
        last2->next = newnode;
        last2 = newnode;
      }
    }

  }
  if(last1 != NULL)
  {
    last1->next = l2;
    return l1;
  }
  return l2;
}
#if 1
void delete_list(struct node_t *top) {
  while (top) {
    struct node_t *temp = top;
    top = top->next;
    free(temp);
  }
}
#endif
#if 0
int main()
{

}
#endif
