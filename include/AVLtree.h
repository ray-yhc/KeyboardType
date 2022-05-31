#ifndef __TREE_H__
#define __TREE_H__
#include "Node.h"

class Tree
{
private:
	Node* root;

public:
	Tree();
	~Tree();
	Node* Insertion(Node*, int);
	void Insert(int input);
	Node* SearchNum(Node* p, int snum);
	Node* Search(int snum);
	Node* getRoot();
	void preOrder(Node*);
	void inOrder(Node*);
	void postOrder(Node*);
	void printTree(Node*, int count=0);
};

#endif