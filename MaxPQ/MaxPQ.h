#include <iostream>

class MaxPQ
{
 public:
  MaxPQ();
  ~MaxPQ();
  void insert(int k);
  int deleteMax();
  int max();
 private:
  int *pq;
  int capacity;
  int N;
  void resize(int size);
  void sink(int k);
  void swim(int k);
  bool less(int i, int j);
  void exch(int i, int j);
};
