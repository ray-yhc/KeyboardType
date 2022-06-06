#ifndef NUM_STACK_H
#define NUM_STACK_H

class Node
{
private:
    int data;        // store data
    Node *next_Node; // Pointer to Next Node
public:
    Node(int);                // Constructor
    int getData();            // return Node's data
    void setNextNode(Node *); // return Pointer to Next Node
    Node *getNextNode();      // set Pointer to Next Node
};

class NumList
{
private:
    Node *head; // Pointer for First Node
public:
    NumList();            // Constructor
    ~NumList();           // Destructor, Delete All Node
    void pushfront(int);  // Insert Data to List at front
    void pushback(int);   // Insert Data to List at back
    bool popfront(int &); // Delete Data fromt List at front
    bool popback(int &);  // Delete Data fromt List at back
    void PrintList();     // Print List
    int getHead();
};

class NumStack : public NumList
{
public:
    void Push(int Data);
    bool Pop(int &Data);
    void PrintStack();
};

//
// 함수정의
//

#include <iostream>
using namespace std;

//
// Node
//

Node::Node(int data)
{ // Constructor
    /************ Implement here ***************/
    this->data = data;
    this->next_Node = NULL;
    /************ Implement here ***************/
}
// Return Node's data
int Node::getData()
{ // return Node's data
    /************ Implement here ***************/
    return this->data;
    /************ Implement here ***************/
}
// Set Pointer to Next Node
void Node::setNextNode(Node *next_Node)
{ // return Pointer to Next Node
    /************ Implement here ***************/
    this->next_Node = next_Node;
    /************ Implement here ***************/
}
// Return Pointer to Next Node
Node *Node::getNextNode()
{ // set Pointer to Next Node
    /************ Implement here ***************/
    return this->next_Node;
    /************ Implement here ***************/
}

//
// List
//

NumList::NumList()
{ // Constructor
    /************ Implement here ***************/
    this->head = NULL;
    /************ Implement here ***************/
}
NumList::~NumList()
{ // Destructor, Delete All Node
    /************ Implement here ***************/
    Node *node = head;
    while (node != NULL)
    {
        this->head = node->getNextNode();
        delete node;
        node = this->head;
    }
    /************ Implement here ***************/
}
void NumList::pushfront(int Data)
{ // Insert Data to List at front
    /************ Implement here ***************/
    Node *node = new Node(Data);
    if (head != NULL)
        node->setNextNode(this->head);
    this->head = node;
    /************ Implement here ***************/
}
void NumList::pushback(int Data)
{ // Insert Data to List at back
    /************ Implement here ***************/
    Node *node = head;
    if (head == NULL)
        head = new Node(Data);
    else
    {
        while (node->getNextNode() != NULL)
        {
            node = node->getNextNode();
        }
        node->setNextNode(new Node(Data));
    }
    /************ Implement here ***************/
}
bool NumList::popfront(int &Data)
{ // Delete Data fromt List at front
    /************ Implement here ***************/
    if (head == NULL)
    {
        cout << "Error : Empty" << endl;
        return false;
    }
    Node *node = head->getNextNode();
    Data = head->getData();
    delete head;
    head = node;
    return true;
    /************ Implement here ***************/
}
bool NumList::popback(int &Data)
{ // Delete Data fromt List at back
    /************ Implement here ***************/
    // head가 NULL인  경우
    if (head == NULL)
    {
        cout << "Error : Empty" << endl;
        return false;
    }
    Node *node = head;
    Node *prev = NULL;

    // List에 하나의 Node 밖에 없는경우
    if (node->getNextNode() == NULL)
    {
        head = NULL;
    }
    // List에 둘 이상의 Node가 있는경우
    else
    {
        while (node->getNextNode() != NULL)
        {
            prev = node;
            node = node->getNextNode();
        }
        prev->setNextNode(NULL);
    }
    Data = node->getData();
    delete node;
    return true;
    /************ Implement here ***************/
}
void NumList::PrintList()
{ // Print List
    /************ Implement here ***************/
    if (head == NULL)
        cout << "Empty" << endl;
    else
    {
        Node *node = head;
        cout << "Data : ";
        while (node != NULL)
        {
            cout << node->getData() << " ";
            node = node->getNextNode();
        }
        cout << endl;
    }
    /************ Implement here ***************/
}
int NumList ::getHead()
{
    return (head == NULL) ? -1 : this->head->getData();
}

//
// STACK
//
void NumStack::Push(int Data)
{
    pushfront(Data);
}
bool NumStack::Pop(int &Data)
{
    return popfront(Data);
}
void NumStack::PrintStack()
{
    PrintList();
}

#endif
