#include "MaxPQ.h"
using namespace std;

MaxPQ::MaxPQ()
{
  capacity = 1;
  N= 0;
  pq = new int[capacity+1];
  cout << "Constr(capacity,N)" << capacity << "," << N << endl;
}

MaxPQ::~MaxPQ()
{
  delete[] pq;
}

void MaxPQ::resize(int size)
{
  int *temp = new int[size+1];
  for (int i=1; i<=N;i++)
  {
    temp[i]=pq[i];
  }
  pq = temp;
  capacity= size;
  cout << "Resize(capacity,N)" << capacity << "," << N << endl;
}

void MaxPQ::insert(int k)
{
  if (N==capacity)
  {
    resize(2*capacity);
  }
  pq[++N]=k;
  swim(N);
}

bool MaxPQ::less(int i, int j)
{
  return pq[i] < pq[j];
}

void MaxPQ::exch(int i, int j)
{
  int temp = pq[i];
  pq[i]=pq[j];
  pq[j]=temp;
}

void MaxPQ::swim(int k)
{
  while (k >1 && less(k/2,k))
  {
    exch(k/2,k);
    k=k/2;
  }
}

void MaxPQ::sink(int k)
{
  while (2*k<=N)
  {
    int j=2*k;
    if (j< N && less(j,j+1)) j++;
    if (!(less(k,j))) break;
    exch(k,j);
    k=j;
  }
}

int MaxPQ::deleteMax()
{
  int max = pq[1];
  pq[1]=pq[N--];
  sink(1);
  if (N>0 && N == capacity/4) resize(capacity/2);

  return max;
}

int MaxPQ::max()
{
  return pq[1];
}

int main(int argc, const char* argv[])
{
  MaxPQ pq;
  pq.insert(2);
  pq.insert(1);
  pq.insert(20);
  pq.insert(3);
  pq.insert(32);
  pq.insert(331);
  pq.insert(123);
  pq.insert(13323);
  pq.insert(23);
  cout << pq.deleteMax()<<endl;
  cout << pq.deleteMax()<<endl;
  cout << pq.deleteMax()<<endl;
  cout << pq.deleteMax()<<endl;
  cout << pq.deleteMax()<<endl;
  cout << pq.deleteMax()<<endl;
  cout << pq.max()<<endl;
}
