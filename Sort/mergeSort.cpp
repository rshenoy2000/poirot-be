#include <iostream>

using namespace std;

void merge(int a[],int copy[],int lo, int mid, int hi)
{
  for (int k=lo;k<=hi;k++)
  {
    copy[k]=a[k];
  }
  int i=lo;int j=mid+1;
  
  for (int k=lo;k<=hi;k++)
  {
    if (i>mid) a[k] = copy[j++];
    else if (j>hi) a[k]=copy[i++];
    else if (copy[j]<copy[i]) a[k]=copy[j++];
    else a[k]=copy[i++];
  }
}

void sort(int a[], int copy[], int lo, int hi)
{
  if (lo>=hi) return;
  int mid = lo+(hi-lo)/2;
  sort(a,copy,lo,mid);
  sort(a,copy,mid+1,hi);
  merge(a,copy,lo,mid,hi);
}
print (int a[],int len)
{
  cout << "Start Print" << endl;
  for (int i=0;i<len;i++)
  {
    cout << a[i] << endl;
  }
  cout << "End Print" << endl;
}
int main()
{
  int a[]={23,4,3,57,45};
  int copy[5];
  print(a,5);
  sort(a,copy,0,4);
  print(a,5);
}
