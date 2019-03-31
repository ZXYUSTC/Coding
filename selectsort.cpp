void selectsort(vector<int> &nums)
{
  for(int i=0;i<nums.size();i++)
  {
    int k=i;
    for(int j=i+1;j<nums.size();j++)
    {
      if(a[k]>a[j])
      {
        k = j;
      }
    }
    if(k!=i)
    {
      int tmp = a[i];
      a[i] = a[k];
      a[k] = tmp;
    }
  }
}
