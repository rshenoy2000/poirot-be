/*
  Weighted Union Find with path compression
 */
#include <bool>
class UF
{
 public:
  UF(int size);
  ~UF();
  void union(int a, int b);
  int find(int a);
  bool connected(int a, int b);
  int count();
  
 private:
  int *id, *sz;
  int count;  
} 
