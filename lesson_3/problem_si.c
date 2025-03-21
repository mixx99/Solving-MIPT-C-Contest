int moveright(int *arr, int key, int last) {
  while(last > 0 && arr[last-1] > key)
  {
    arr[last] = arr[(last)-1];
    last--;
  }
  return last;
}
