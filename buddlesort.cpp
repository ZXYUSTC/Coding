void buddlesort(vector<int> &nums)
{
  for(int i=0;i<nums.size()-1;i++)
  {
    for(int j=0;j<nums.size()-i-1;j++)
    {
      if(a[j]>a[j+1])
      {
        int tmp = a[j];
        a[j] = a[j+1];
        a[j+1] = tmp;
      }
    }
  }
}
