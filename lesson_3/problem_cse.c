typedef int (*cmp_t)(void const * lhs, void const * rhs);

void swap(void* el1, void* el2, int eltsize)
{
    unsigned char temp[eltsize];
    memcpy(temp, el1, eltsize);
    memcpy(el1, el2, eltsize);
    memcpy(el2, temp, eltsize);
}



int selstep(void * parr, int eltsize, int numelts, int nsorted, cmp_t cmp)
{
  int idx_min, i, counter  = 0;
  void* min;
  while(counter < numelts)
  {
    unsigned char* arr = (unsigned char*) parr;
    min = (void*) arr + counter * eltsize;
    idx_min = counter;
    for(i = counter; i < numelts; ++i)
    {
      void* now = arr + i * eltsize;
      if(cmp(now, min))
      {
              min = now;
              idx_min = i;
      }
    }
    if(idx_min != counter)
    {
      swap((arr + idx_min * eltsize), (arr + counter * eltsize), eltsize);
      return 0;
    }
    counter++;
  }
  return 0;
}
