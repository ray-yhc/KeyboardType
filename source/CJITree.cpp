#include "CJITree.h"
#include <iostream>
using namespace std;
#pragma warning(disable : 4996)

cjiNode::cjiNode(int _signal, const char *_input, const char *_output)
{
    strcpy(input, _input);
    strcpy(output, _output);
    signal = _signal;
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
// cjiNode* cjiNode::getLeft(){
//     return left;
// }
cjiNode *cjiNode::getRight()
{
    return right;
}
// void cjiNode::setLeft(cjiNode* left){
//     this->left = left;
// }
void cjiNode::setRight(cjiNode *right)
{
    this->right = right;
}

int cjiNode::cmpPriority(int _signal, const char *_input)
{ // this의 priority가 높으면  양수, 낮으면 음수, 같으면 0
    if (this->signal == _signal)
    {
        return strcmp(_input, this->input);
    }
    return (_signal - this->signal);
}

CJITree::CJITree()
{
    head = NULL;
}

CJITree::~CJITree()
{
}

void CJITree::pushfront(cjiNode *New_Node)
{                                 // Insert Data to List at front
    if (head != NULL)             // If List isn't empty
        New_Node->setRight(head); // New Node's Next Node is First Node
    head = New_Node;              // Head change to New Node
}
void CJITree::pushback(cjiNode *New_Node)
{                        // Insert Data to List at back
    cjiNode *temp;       // Pointer for searching
    if (head == NULL)    // If List is empty
        head = New_Node; // Head is New Node
    else
    {
        temp = head; // Searhing Last Node from front
        // temp move to back until NextNode is NULL
        while (temp->getRight() != NULL)
        {
            temp = temp->getRight();
        }
        temp->setRight(New_Node); // Last Node's Next Node is New Node
    }
}

char *CJITree::searchOutput(int _signal, const char *_input)
{
    if (head == NULL)
    {
        // cout << "There is no " << searchString << " Data Node" << endl;
        return NULL;
    }
    else
    {
        // char compare[10];
        // strcpy(compare, searchString.c_str());

        int index = 0;
        int result = -1;
        cjiNode *node = head;
        while (index == 0 || node != NULL)
        {

            if (node->cmpPriority(_signal, _input) == 0)
            {
                result = index;
                return node->getoutput(); //끝!
                // break;
            }
            node = node->getRight();
            index++;
        }

        if (result == -1)
        {
            // cout << "There is no " << searchString << " Data Node" << endl;
            return NULL;
        }
    }
}

void CJITree::PrintList()
{                                // Print List
    if (head == NULL)            // If List is empty
        cout << "Empty" << endl; // Print out Error Message
    else
    {
        cjiNode *Print_Node = head;
        // cout << "Data : " ;
        while (Print_Node != NULL)
        { // If Node is not NULL
            cout << Print_Node->getsignal() << "\t" << Print_Node->getinput() << "\t" << Print_Node->getoutput() << endl;
            Print_Node = Print_Node->getRight(); // Move to Next Node
        }
        cout << endl;
    }
}