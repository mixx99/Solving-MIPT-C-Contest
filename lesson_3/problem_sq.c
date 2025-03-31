unsigned partition(int *arr, unsigned low, unsigned high) 
{
  unsigned i = low + 1;
  unsigned j = high;
  unsigned tmp;
  while (1) 
  {
    while (i <= j && arr[i] <= arr[low]) i++;  
    while (i <= j && arr[j] > arr[low]) j--;

    if (i >= j) break; 

    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  }
  tmp = arr[low];
  arr[low] = arr[j];
  arr[j] = tmp;

  return j; 
}
