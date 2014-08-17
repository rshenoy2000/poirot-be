#include "BST.h"
#include <iostream>
#include <sstream>
using namespace std;

Node::Node(int key, string value)
{
  this->key = key;
  this->value = value;
  this->left = nullptr;
  this->right = nullptr;
}

BST::BST()
{
  _size = 0;
}

bool BST::isEmpty()
{
  if (_size==0) return true;
  return false;
}

void BST::put(int key, string value, NodePtr node)
{
  if (key==node->key)
  {
    node->value = value;
  }  
  else if (key < node->key)
  {
    if (!node->left)
    {
      NodePtr newNode = new Node(key,value);
      cout << "newNode: " << newNode << ","<<key<<":"<<value<<endl;
      node->left=newNode;
    }
    else
    {
      put(key,value,node->left);
    }
  }
  else if (key > node->key)
  {
    if (!node->right)
    {
      NodePtr newNode = new Node(key,value);
      cout << "newNode: " << newNode << ","<<key<<":"<<value<<endl;
      node->right = newNode;
    }
    else
    {
      put(key,value,node->right);
    }
  }
}

int BST::size()
{
  return _size;
}

void BST::put(int key, string value)
{
  if (isEmpty())
  {
    root = new Node(key,value);
    cout << "root: " << root << ","<<key<<":"<<value<<endl; 
  }
  else
  {
    put(key,value,root);
  }
  _size++;
}

string BST::get(int key, NodePtr node)
{
  if (node->key == key) return node->value;
  else if (key < node->key)
  {
    if (!(node->left))return EMPTY;
    return get(key,node->left);
  }
  else if (key > node->key)
  {
    if (!(node->right))return EMPTY;
    return get(key,node->right);
  }
}
      
string BST::get(int key)
{
  if (isEmpty())
  {
    return EMPTY;
  }
  else
  {
    return get(key,root);
  }
} 

int BST::min()
{
  if (!isEmpty()) return min(root)->key;
  return -1;
}

NodePtr BST::min(NodePtr node)
{
  if (!node->left) return node;
  else return min(node->left);
}

NodePtr BST::deleteMinNode(NodePtr node)
{
  NodePtr retNode = node;
  if (!(node->right) && !(node->left))
  {
    retNode= nullptr;
    delete node;
    _size--;
  }
  else if (!(node->left))
  {
    retNode= node->right;
  }
  else
  {
    retNode= deleteMinNode(node->left);
  }
  return retNode; 
}
NodePtr BST::deleteNode(NodePtr node)
{
  NodePtr retNode = node;

  if ((node->left) &&(node->right))
  {
    NodePtr minnode = min(node->right);
    retNode->key = minnode->key;
    retNode->value = minnode->value;
    retNode->right=deleteMinNode(node->right);
    retNode->left= node->left;
  }  
  else
  {
    if (!(node->left) &&!(node->right))
    {
      retNode=nullptr;
    }
    else if (!(node->left))
    {
      retNode= node->right;
    }
    else if (!(node->right))
    {
      retNode= node->left;
    }
    delete node;
    _size--;
  }

  return retNode;
}

NodePtr BST::deleteKey(int key, NodePtr node)
{
  if (!node) return nullptr;
  NodePtr retNode = node;
  if (node->key == key) 
  {
    retNode= deleteNode(node);
  }
  else if (key<node->key)
  {
    retNode->left= deleteKey(key,node->left);
  }
  else 
  {
    retNode->right= deleteKey(key,node->right);
  }
  return retNode;
}


void BST::deleteKey(int key)
{
  if (isEmpty()) return;
  root = deleteKey(key,root);
}

void BST::printNode(string val, int xpos, int ypos)
{
  map<int,string> vecval;

  if (buffer.find(ypos) != buffer.end())
  {
    vecval = buffer[ypos];
  }
  vecval[xpos]=val;
  buffer[ypos]=vecval;
}


void BST::printNode(NodePtr node, int xpos, int ypos)
{
  stringstream ss;
  ss<<node->key;

  int size =ss.str().length();
  printNode(ss.str(),xpos,ypos);
  if (node->left)
  {
    printNode("/",xpos-size/2,ypos+1);
    printNode(node->left,xpos-2,ypos+2);
  }
  if (node->right)
  {
    printNode("\\",xpos+size/2,ypos+1);
    printNode(node->right,xpos+2,ypos+2);
  }
}


void BST::print()
{
  printNode(root,5,5);
  cout << " printing " << endl;
  for (map<int, map<int,string>>::iterator i=buffer.begin();i!=buffer.end();i++)
  {
    map<int,string> val = i->second;
    int current = 0;
    for (map<int,string>::iterator j=val.begin();j!=val.end();j++)
    {

      for (int k=current; k<j->first; k++)
      {
	cout <<" ";
      }
      current = j->first;
      cout << j->second  ;
    }
    cout << endl;
  } 
 
}

int main()
{
  BST* bst = new BST();
  cout << bst->size() << endl;
  bst->put(13,"3");
  bst->put(27,"7");
  bst->put(30,"0");
  bst->put(41,"1");
  bst->put(27,"7");
  bst->put(80,"0");
  bst->put(11,"1");
  bst->put(73,"7");
  bst->put(100,"0");
  bst->put(120,"1");
  bst->print();
  
  cout << "sz "<< bst->size() << endl;
  cout << "13:" << bst->get(13) << endl;
  cout << "73:"<< bst->get(73) << endl;
  bst->deleteKey(13);
  bst->deleteKey(73);
  cout << "sz "<< bst->size() << endl;
  cout << "80:" << bst->get(80) << endl;
  cout << "100:"<< bst->get(100) << endl;
  bst->deleteKey(100);
  cout << "sz "<< bst->size() << endl;
  cout << "80:" << bst->get(80) << endl;
  cout << "100:"<< bst->get(100) << endl;
  
}
