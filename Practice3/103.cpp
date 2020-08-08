#include <iostream>

using namespace std;

template <typename T>
class Nod {
	T data;
	Node* next;
public:
	Nod() {}
};

int main()
{
	Nod<int>* node;
	node = new Node<int>(10);
	for (int i = 0; i < 5; i++)
		node->setBack(node, i + 1);
	cout << "intÇü:";
	cout << node << endl;
	DeleteNode(node);

	Node<double>* dnode;
	dnode = new Node<double>(10.5);
	for (int i = 0; i < 5; i++)
		dnode->setBack(dnode, (i + 1) * 1.1);

	cout << "doubleÇü: ";
	cout << dnode << endl;
	DeleteNode(dnode);

	return 0;
}