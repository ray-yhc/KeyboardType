#include "CJITree.h"
#include <iostream>
using namespace std;
#pragma warning(disable : 4996)

//
// Node  d
//

cjiNode::cjiNode(int _signal, const char *_input, const char *_output)
{
    strcpy(input, _input);
    strcpy(output, _output);
    signal = _signal;
    height = 0;
}
cjiNode::~cjiNode()
{
}

char *cjiNode::getinput()
{
    return input;
}
char *cjiNode::getoutput()
{
    return output;
}
int cjiNode::getsignal()
{
    return signal;
}
cjiNode *cjiNode::getLeft()
{
    return left;
}
cjiNode *cjiNode::getRight()
{
    return right;
}
void cjiNode::setLeft(cjiNode *left)
{
    this->left = left;
}
void cjiNode::setRight(cjiNode *right)
{
    this->right = right;
}
int cjiNode::getHeight()
{
    return this->height;
}
void cjiNode::setHeight(int _height)
{
    this->height = _height;
}

int cjiNode::cmpPriority(int _signal, const char *_input)
{ // this의 priority가 높으면  양수, 낮으면 음수, 같으면 0
    if (this->signal == _signal)
    {
        cout << "cmpPriority - " << _signal << _input << this->input << endl; // flag
        return strcmp(_input, this->input);
    }
    return (_signal - this->signal);
}
int cjiNode::cmpPriority(cjiNode *p)
{
    return cmpPriority(p->getsignal(), p->getinput());
}

//
// Calculations for Tree
//

int maxHeight(cjiNode *p)
{
    int l, r;
    l = (p->getLeft() == NULL) ? 0 : p->getLeft()->getHeight();
    r = (p->getRight() == NULL) ? 0 : p->getRight()->getHeight();
    return (l > r) ? l + 1 : r + 1;
}
int getbalanceFactor(cjiNode *p)
{
    int l, r;
    l = (p->getLeft() == NULL) ? 0 : p->getLeft()->getHeight();
    r = (p->getRight() == NULL) ? 0 : p->getRight()->getHeight();
    return l - r;
}

cjiNode *LLrotate(cjiNode *parent)
{
    cjiNode *child = parent->getLeft();
    if (child->getRight() != NULL)
        parent->setLeft(child->getRight());
    else
        parent->setLeft(NULL);
    child->setRight(parent);
    parent->setHeight(maxHeight(parent));
    return child;
}
cjiNode *RRrotate(cjiNode *parent)
{
    cjiNode *child = parent->getRight();
    if (child->getLeft() != NULL)
        parent->setRight(child->getLeft());
    else
        parent->setRight(NULL);
    child->setLeft(parent);
    parent->setHeight(maxHeight(parent));
    return child;
}
cjiNode *LRrotate(cjiNode *p)
{
    p->setLeft(RRrotate(p->getLeft()));
    return LLrotate(p);
}
cjiNode *RLrotate(cjiNode *p)
{
    p->setRight(LLrotate(p->getRight()));
    return RRrotate(p);
}

cjiNode *rebalance(cjiNode *p)
{
    int balanceFactor = getbalanceFactor(p);

    if (balanceFactor > 1)
    {
        if (getbalanceFactor(p->getLeft()) > 0)
            return LLrotate(p);
        else
            return LRrotate(p);
    }
    else if (balanceFactor < -1)
    {
        if (getbalanceFactor(p->getRight()) < 0)
            return RRrotate(p);
        else
            return RLrotate(p);
    }
    else
        return p;
}

//
// Tree
//

CJITree::CJITree() : root(NULL) {}

CJITree::~CJITree()
{
    delete root;
}

cjiNode *CJITree::Insertion(cjiNode *p, cjiNode *newNode)
{
    /************ Implement here ***************/
    cjiNode *temp;
    if (p == NULL)
    {
        newNode->setHeight(1);
        return newNode;
    }
    else if (newNode->cmpPriority(p) < 0)
    { // left로 이동
        temp = Insertion(p->getLeft(), newNode);
        p->setLeft(temp);
    }
    else if (newNode->cmpPriority(p) > 0)
    { // right로 이동
        temp = Insertion(p->getRight(), newNode);
        p->setRight(temp);
    }
    else
    {
        cout << newNode->cmpPriority(p) << endl;
        cout << "The node is pre-exist. please check the data." << endl;
    }

    p->setHeight(maxHeight(p));
    p = rebalance(p);
    return p;
    /*******************************************/
}

void CJITree::Insert(cjiNode *newNode)
{
    root = Insertion(root, newNode);
    // cout<<"inserted "<<input<<endl;
    // postOrder(root);
}

cjiNode *CJITree::SearchNum(cjiNode *p, int _signal, const char *_input)
{
    cjiNode *temp;
    if (p == NULL)
    {
        cout << "No Data" << endl;
        return NULL;
    }
    else if (p->cmpPriority(_signal, _input) > 0)
    {
        cout << "go L" << endl; // flag
        return SearchNum(p->getLeft(), _signal, _input);
    }
    else if (p->cmpPriority(_signal, _input) < 0)
    {
        cout << "go R" << endl; // flag
        return SearchNum(p->getRight(), _signal, _input);
    }
    else
    {
        cout << "Result : " << p->getsignal() << "|" << p->getinput() << "|" << p->getoutput() << endl;
        return p;
    }
}

char *CJITree::Search(int _signal, const char *_input)
{
    cout << "search - " << _signal << _input << endl;
    cjiNode *node = SearchNum(root, _signal, _input);
    return node->getoutput();
}

cjiNode *CJITree::getRoot()
{
    return root;
}

void CJITree::printTree(cjiNode *cNode, int count)
{
    if (cNode == NULL)
        return;
    printTree(cNode->getRight(), count + 1);

    if (cNode == root)
    {
        cout << "AVL Tree";
    }
    else
    {
        for (int i = 0; i <= count; i++)
        {
            cout << "\t";
        }
    }
    cout << "->" << cNode->getsignal() << "|" << cNode->getinput() << "|" << cNode->getoutput() << endl;

    printTree(cNode->getLeft(), count + 1);

    if (cNode == root)
        cout << "Height : " << root->getHeight() << endl;
    ;
}

// //problem 1-6
// void Tree::preOrder(cjiNode* cNode) {
// 	/************ Implement here ***************/
// 	if (cNode==NULL) return;
// 	cout<< cNode->getNum() << " " <<endl;
// 	preOrder(cNode->getLeft());
// 	preOrder(cNode->getRight());
// 	/*******************************************/
// }

// //problem 1-7
// void Tree::inOrder(cjiNode* cNode) {
// 	/************ Implement here ***************/
// 	if (cNode==NULL) return;
// 	inOrder(cNode->getLeft());
// 	cout<< cNode->getNum() << " " <<endl;
// 	inOrder(cNode->getRight());
// 	/*******************************************/
// }

// //problem 1-8
// void Tree::postOrder(cjiNode* cNode) {
// 	/************ Implement here ***************/
// 	if (cNode==NULL) return;
// 	postOrder(cNode->getLeft());
// 	postOrder(cNode->getRight());
// 	cout<< cNode->getNum() << " " <<cNode->getHeight()<<endl;
// 	/*******************************************/
// }

// CJITree::CJITree()
// {
//     root = NULL;
// }

// CJITree::~CJITree()
// {
// }

// void CJITree::pushfront(cjiNode *New_Node)
// {                                 // Insert Data to List at front
//     if (root != NULL)             // If List isn't empty
//         New_Node->setRight(root); // New Node's Next Node is First Node
//     root = New_Node;              // root change to New Node
// }
// void CJITree::pushback(cjiNode *New_Node)
// {                        // Insert Data to List at back
//     cjiNode *temp;       // Pointer for searching
//     if (root == NULL)    // If List is empty
//         root = New_Node; // root is New Node
//     else
//     {
//         temp = root; // Searhing Last Node from front
//         // temp move to back until NextNode is NULL
//         while (temp->getRight() != NULL)
//         {
//             temp = temp->getRight();
//         }
//         temp->setRight(New_Node); // Last Node's Next Node is New Node
//     }
// }

// char *CJITree::searchOutput(int _signal, const char *_input)
// {
//     if (root == NULL)
//     {
//         // cout << "There is no " << searchString << " Data Node" << endl;
//         return NULL;
//     }
//     else
//     {
//         // char compare[10];
//         // strcpy(compare, searchString.c_str());

//         int index = 0;
//         int result = -1;
//         cjiNode *node = root;
//         while (index == 0 || node != NULL)
//         {

//             if (node->cmpPriority(_signal, _input) == 0)
//             {
//                 result = index;
//                 return node->getoutput(); //끝!
//                 // break;
//             }
//             node = node->getRight();
//             index++;
//         }

//         if (result == -1)
//         {
//             // cout << "There is no " << searchString << " Data Node" << endl;
//             return NULL;
//         }
//     }
// }

// void CJITree::PrintList()
// {                                // Print List
//     if (root == NULL)            // If List is empty
//         cout << "Empty" << endl; // Print out Error Message
//     else
//     {
//         cjiNode *Print_Node = root;
//         // cout << "Data : " ;
//         while (Print_Node != NULL)
//         { // If Node is not NULL
//             cout << Print_Node->getsignal() << "\t" << Print_Node->getinput() << "\t" << Print_Node->getoutput() << endl;
//             Print_Node = Print_Node->getRight(); // Move to Next Node
//         }
//         cout << endl;
//     }
// }