/*
  Weighted Union Find with path compression
 */

class UF
{
 public:
  UF(int size);
  ~UF();
  void doUnion(int a, int b);
  int find(int a);
  bool connected(int a, int b);
  int count();
  
 private:
  int *id, *sz;
  int _count;  
}; 
