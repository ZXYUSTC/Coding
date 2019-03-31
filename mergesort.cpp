void merge(vector<int> &nums, int s, int mid, int e)
{
  vector<int> tmp(s-e+1,0);
  int i = s, j = mid+1;
  int k =0;
  while(s<=mid && j<=e)
  {
    if(nums[i]<=nums[j])
    {
      tmp[k++]=nums[i++];
    }
    else
    {
      tmp[k++]=nums[j++];
    }
  }
  while(i<=mid)
  {
    tmp[k++]=nums[i++];
  }
  while(j<=e)
  {
    tmp[k++]=nums[j++];
  }
  for(int index = 0; index<s-e+1;index++)
  {
    nums[s+index]=tmp[index];
  }
}
void MergeSort(vector<int> &nums, int s, int e)
{
  if(s>=e)
  {
    return;
  }
  int mid = (s+e)/2;
  MergeSort(nums, s, mid);
  MergeSort(nums, mid+1,e);
  merge(nums, s, mid, e);
}
