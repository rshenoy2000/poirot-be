#include <memory>
#include <string>
#include <cstddef>
#include <vector>
#include <map>

using namespace std;

class Node;
typedef Node* NodePtr ;
class Node {
  public:
    int key;
    string value;
    NodePtr left;
    NodePtr right;
    Node(int key, string value);
};

const string EMPTY="";

class BST
{
public:
  BST();
  ~BST();
  void put(int key, string value);
  string get(int key);
  void deleteKey(int key);
  //  bool contains(int key);
  bool isEmpty();
  int size();
  int min();
  //  int max();
  //  int ceiling(int key);
  //int floor(int key);
  //  int rank(int key);
  //  int select(int k);
  void deleteMin();
  //  void deleteMax();
  void print();
 private:
  NodePtr root;
  int _size;
  map<int,map<int,string> > buffer;
  void put(int key, string value, NodePtr node);
  string get(int key, NodePtr node);
  NodePtr deleteNode(NodePtr node);
  NodePtr deleteMinNode(NodePtr node);
  NodePtr min(NodePtr node);
  NodePtr deleteKey(int key, NodePtr node);
  void printNode(string val, int x, int y);
  void printNode(NodePtr node, int x, int y);

};
