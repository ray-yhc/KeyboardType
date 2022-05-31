#ifndef CJI_TREE_H
#define CJI_TREE_H

#include <string.h>

class cjiNode
{
protected:
    char input[3];
    char output[3];
    int signal;

    // cjiNode *left;
    cjiNode *right;

public:
    cjiNode(int _signal, const char *_input, const char *_output);
    ~cjiNode();

    char *getinput();
    char *getoutput();
    int getsignal();
    // cjiNode* getLeft();
    cjiNode *getRight();
    // void setLeft(cjiNode *right);
    void setRight(cjiNode *right);

    int cmpPriority(int _signal, const char *_input); // this의 priority가 높으면  양수, 낮으면 음수, 같으면 0
    // int compare(const char c[3]);  //맞는 글자인지 검색
    // char *geteng();                // eng 반환
    // int getuni();                  // uni 반환
    // Hangul *getNext();             //다음노드 반환
    // void setNext(Hangul *_hangul); //다음노드 설정
};

class CJITree
{
private:
    cjiNode *head; // Pointer for First Node
public:
    CJITree();                         // Constructor
    ~CJITree();                        // Destructor
    void pushfront(cjiNode *New_Node); // Insert Data to List at front
    void pushback(cjiNode *New_Node);  // Insert Data to List at back
    // bool popfront(string &Data);     // Delete Data fromt List at front
    // bool popback(string &Data);      // Delete Data fromt List at back
    char *searchOutput(int _signal, const char *_input);
    // int indexToUnicode(int index);
    void PrintList(); // Print List
};

#endif



// class Node {
// private:
// 	int num;
// 	Node* left;
// 	Node* right;
// 	int height;

// public:
// 	Node(int _num, Node* _left, Node* _right);
// 	Node* getLeft(void);
// 	Node* getRight(void);
// 	void setLeft(Node* node);
// 	void setRight(Node* node);
// 	int getNum(void);
// 	int getHeight();
// 	void setHeight(int);
// };


// Node* Node::getLeft(void) {
// 	return left;
// }

// Node* Node::getRight(void) {
// 	return right;
// }

// int Node::getNum() {
// 	return num;
// }

// void Node::setLeft(Node* node) {
// 	left = node;
// }

// void Node::setRight(Node* node) {
// 	right = node;
// }
// int Node::getHeight(){
// 	return this->height;
// }
// void Node::setHeight(int _height){
// 	this->height = _height;
// }

// Node::Node(int _num, Node* _left, Node* _right)
// 	:num(_num), left(_left), right(_right), height(0) {}
