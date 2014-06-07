#include "UF.h"
#include <iostream>
using namespace std;

UF::UF(int size)
{
  id = new int[size];
  sz = new int[size];
  _count = size;
  for (int i=0; i<size;i++)
  {
    id[i]=i;
    sz[i]=1;
  }
}
UF::~UF()
{
  delete[] id;
  delete[] sz;
}

int UF::find(int a)
{
  int root = a;
  while (root!=id[root])
  {
    root = id[root];
  }
  /* Path compression */
  while (a!=root)
  {
    int newa = id[a];
    id[a]=root;
    a = newa;
  }
}

bool UF::connected(int a,int b)
{
  return find(a)==find(b);
}

void UF::doUnion(int a, int b)
{
  if (connected(a,b)) return;
  int roota = find(a);
  int rootb = find(b);
  if (sz[roota] < sz[rootb])
  {
    id[roota]=rootb;
    sz[rootb]+=sz[roota];
  }
  else
  {
    id[rootb]=roota;
    sz[roota]+=sz[rootb];
  }
  _count--;
}

int UF::count()
{
  return _count;
}

int main(int argc, const char* argv[])
{
  UF testUF(5);
  testUF.doUnion(0,1);
  testUF.doUnion(0,2);
  testUF.doUnion(1,3);
  testUF.doUnion(4,3);
  cout << testUF.connected(0,2) << endl;
}
