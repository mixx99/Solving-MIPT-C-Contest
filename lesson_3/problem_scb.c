typedef int (*cmp_t)(const void *lhs, const void *rhs);


/* Здесь key это элемент, который ищется, base это массив в котором осуществляется поиск, size это размер элементов массива (и, соответственно, элемента key), num это количество элементов в массиве */
/* Компаратор возвращает отрицательное число, если lhs логически меньше, чем rhs, 0 если они равны и положительное число, если lhs логически больше, чем rhs */
void *cbsearch(const void *key, const void *base, int num, int size, cmp_t cmp)
{
  int l = 0;
  int r = num - 1;
  while(l <= r)
  {
    unsigned char* arr = (unsigned char*) base;
    int m = l + (r - l) / 2;

    if(cmp((void*) arr + m * size, key) == 0) return (void*) arr + m * size;
    if(cmp((void*) arr + m * size, key) < 0) l = m + 1;
    if(cmp((void*) arr + m * size, key) > 0) r = m - 1;
  }
  return NULL;
}
