void merge(int *arr, int l, int m, int r) 
{
  int i = l, j = m + 1, cnt = 0;
  int length = r - l + 1;
  int *arr2 = calloc(length, sizeof(int));
  while(i <= m || j <= r)
  {
    if(i > m)
    {
      arr2[cnt] = arr[j];
      j++;
      cnt++;
      continue;
    }
    if(j > r)
    {
      arr2[cnt] = arr[i];
      i++;
      cnt++;
      continue;
    }
    if(arr[i] < arr[j])
    {
      arr2[cnt] = arr[i];
      cnt++;
      i++;
      continue;
    }
    if(arr[j] <= arr[i])
    {
      arr2[cnt] = arr[j];
      cnt++;
      j++;
      continue;
    }
  }
  for(int i = 0, j = l; i < length; ++i, ++j)
    arr[j] = arr2[i];
  free(arr2);
}
