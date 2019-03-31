int partition(vector<int> &nums, int s, int e)
{
  int tmp = nums[s];
  int i = s, j = e;
  while(i<j)
  {
    while(i<j&&nums[j]>=tmp)
    {
      j--;
    }
    a[i] = a[j];
    while(i<j&&nums[i]<=tmp)
    {
      i++;
    }
    a[j]=a[i];
  }
  a[i] = tmp;
  return i;
}
void quicksort(vector<int> &nums, int s, int e)
{
  if(s>=e)
  {
    return;
  }
  int mid = partition(nums,s,e);
  quicksort(nums, s, mid-1);
  quicksort(nums, mid+1, e);
}
