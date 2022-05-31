#include "AVLtree.h"

int maxHeight(Node*p){
	int l, r;
	l = (p->getLeft() == NULL)? 0  : p->getLeft()->getHeight();
	r = (p->getRight() == NULL)? 0  : p->getRight()->getHeight();
	return (l>r)? l+1 : r+1;
}
int getbalanceFactor(Node* p){
	int l, r;
	l = (p->getLeft() == NULL)? 0  : p->getLeft()->getHeight();
	r = (p->getRight() == NULL)? 0  : p->getRight()->getHeight();
	return l-r;
}

Node* LLrotate(Node* parent){
	Node * child = parent->getLeft();
	if (child->getRight() != NULL)
		parent->setLeft(child->getRight());
	else
		parent->setLeft(NULL);
	child->setRight(parent);
	parent->setHeight(maxHeight(parent));
	return child;
}
Node* RRrotate(Node* parent){
	Node * child = parent->getRight();
	if (child->getLeft() != NULL)
		parent->setRight(child->getLeft());
	else
		parent->setRight(NULL);
	child->setLeft(parent);
	parent->setHeight(maxHeight(parent));
	// cout<<parent->getHeight()<<endl;
	return child;
}
Node* LRrotate(Node* p){
	p->setLeft( RRrotate(p->getLeft()) );
	return LLrotate(p);
}
Node* RLrotate(Node* p){
	p->setRight( LLrotate(p->getRight()) );
	return RRrotate(p);
}

Node* rebalance(Node* p){
	int balanceFactor = getbalanceFactor(p);

	if(balanceFactor>1){
		if(getbalanceFactor(p->getLeft()) >0)
			return LLrotate(p);
		else
			return LRrotate(p);
	}
	else if(balanceFactor<-1){
		if(getbalanceFactor(p->getRight()) <0)
			return RRrotate(p);
		else
			return RLrotate(p);
	}
	else 
		return p;
}

Tree::Tree() : root(NULL) {}

Tree::~Tree() {
	delete root;
}

//problem 1-1
Node* Tree::Insertion(Node* p, int input) {
	/************ Implement here ***************/
	Node *newNode, *temp ;
	if (p == NULL){
		newNode = new Node(input, NULL, NULL);
		newNode->setHeight(1);
		return newNode;
	}else if(input < p->getNum()){ // left로 이동
		temp = Insertion(p->getLeft(), input);
		p->setLeft(temp);
	}else if (input > p->getNum()){ // right로 이동
		temp = Insertion(p->getRight(), input);
		p->setRight(temp);
	}else{
		cout<<"The number is pre-exist. please check the number."<<endl;
	}	

	p->setHeight( maxHeight(p) ); 
	p = rebalance(p);
	return p;
	/*******************************************/
}

//problem 1-2
void Tree::Insert(int input) {
	/************ Implement here ***************/
	root = Insertion(root,input);
	// cout<<"inserted "<<input<<endl;
	// postOrder(root);
	/*******************************************/
}


//problem 1-3
Node* Tree::SearchNum(Node* p, int snum) {
	/************ Implement here ***************/
	Node* temp;
	if (p == NULL){
		cout<<"No Data"<<endl;
		return NULL;

	}else if(snum < p->getNum()){
		return SearchNum(p->getLeft(), snum);
	}else if(snum > p->getNum()){
		return SearchNum(p->getRight(), snum);
	}else{
		cout<<"Result : "<< p->getNum() <<endl;
		return p;
	}
	/*******************************************/
}


//problem 1-4
Node* Tree::Search(int snum) {
	/************ Implement here ***************/
	return SearchNum(root, snum);
	/*******************************************/
}

//problem 1-5
Node* Tree::getRoot() {
	/************ Implement here ***************/
	return root;
	/*******************************************/
}

//problem 1-6
void Tree::preOrder(Node* cNode) {
	/************ Implement here ***************/
	if (cNode==NULL) return;
	cout<< cNode->getNum() << " " <<endl;
	preOrder(cNode->getLeft());
	preOrder(cNode->getRight());
	/*******************************************/
}

//problem 1-7
void Tree::inOrder(Node* cNode) {
	/************ Implement here ***************/
	if (cNode==NULL) return;
	inOrder(cNode->getLeft());
	cout<< cNode->getNum() << " " <<endl;
	inOrder(cNode->getRight());
	/*******************************************/
}

//problem 1-8
void Tree::postOrder(Node* cNode) {
	/************ Implement here ***************/
	if (cNode==NULL) return;
	postOrder(cNode->getLeft());
	postOrder(cNode->getRight());
	cout<< cNode->getNum() << " " <<cNode->getHeight()<<endl;
	/*******************************************/
}

void Tree::printTree(Node* cNode, int count){
	if (cNode==NULL) return;
	printTree(cNode->getRight(), count+1 );
	
	if(cNode == root){
		cout<< "AVL Tree";
	}else{
		for(int i=0; i<=count ; i++){
			cout<<"\t";
		}
	}
	
	cout<< "->"<< cNode->getNum() << " " <<endl;
	printTree(cNode->getLeft(), count+1 );

	
	if(cNode == root)
		cout<< "Height : "<< root->getHeight()<<endl;;
}