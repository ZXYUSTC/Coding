void buddlesort(vector<int> &nums)
{
  bool flag = false;
  for(int i=0;i<nums.size()-1;i++)
  {
    flag = false;
    for(int j=0;j<nums.size()-i-1;j++)
    {
      if(a[j]>a[j+1])
      {
        flag = true;
        int tmp = a[j];
        a[j] = a[j+1];
        a[j+1] = tmp;
      }
      if(flag == false)
      {
        break;
      }
    }
  }
}
