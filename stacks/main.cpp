#include <iostream>
using namespace std;

class Stack {
	public:
	struct Node
	{
		int data;
		Node* next;
	};
	Node* top;
	Node* pop();
	void push(int data);
};

Stack::Node* Stack::pop()
{
	if (top != NULL)
	{
		Node* item = top;
		top=top->next;
		return item;
	}
	return NULL;
}

void Stack::push(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = top;
	top = newNode;
}

extern "C" int main(int argc, char** argv)
{
	Stack* myStack = new Stack();
	myStack->push(3);
	myStack->push(10);
	cout << myStack->pop()->data << endl;

}
