#include "LinkedList.h"
#include <iostream>
using namespace std;
#pragma warning(disable : 4996)

List::List()
{
	head = NULL; // Initialize head
	name = '_';
}
List::List(string _name)
{				 // Constructor
	head = NULL; // Initialize head
	name = _name;
}
List::~List()
{								// Destructor, Delete All Node
	Hangul *Delete_Node = head; // Delete Node from front to back
	while (Delete_Node != NULL)
	{								   // If Node isn't NULL
		head = Delete_Node->getNext(); // Head is Second Node
		delete Delete_Node;			   // Delete First Node
		Delete_Node = head;			   // Move to Second Node
	}
}
string List::getListName()
{
	return name;
}
void List::pushfront(Hangul *New_Node)
{								 // Insert Data to List at front
	if (head != NULL)			 // If List isn't empty
		New_Node->setNext(head); // New Node's Next Node is First Node
	head = New_Node;			 // Head change to New Node
}
void List::pushback(Hangul *New_Node)
{						 // Insert Data to List at back
	Hangul *temp;		 // Pointer for searching
	if (head == NULL)	 // If List is empty
		head = New_Node; // Head is New Node
	else
	{
		temp = head; // Searhing Last Node from front
		// temp move to back until NextNode is NULL
		while (temp->getNext() != NULL)
		{
			temp = temp->getNext();
		}
		temp->setNext(New_Node); // Last Node's Next Node is New Node
	}
}
bool List::popfront(char *Data)
{ // Delete Data fromt List at front
	if (head == NULL)
	{ // If List is empty
		// cout << "Error : Empty" << endl;	// Print out Error Message
		return false; // Return false;
	}
	Hangul *Delete_Node = head; // Deleted Node is First Node
	head = head->getNext();		// Head change to Second Node
	// Return Deleted Node's Data by reference
	strcpy(Data, Delete_Node->geteng());
	delete Delete_Node; // Delete Node
	return true;		// Return Data
}
// bool List::popback(Datatype &Data)
// { // Delete Data fromt List at back
// 	if (head == NULL)
// 	{ // If List is empty
// 		// cout << "Error : Empty" << endl;// Print out Error Message
// 		return false; // Return false;
// 	}
// 	Node *prev_Node = head;	  // Initialize Pointer for Previous Node
// 	Node *Delete_Node = head; // Initialize Pointer for Deleted Node
// 	// Search Last Node from front to back
// 	while (Delete_Node->getNextNode() != NULL)
// 	{
// 		prev_Node = Delete_Node;
// 		Delete_Node = Delete_Node->getNextNode();
// 	}
// 	if (prev_Node == Delete_Node) // If Last Node is same with Before Node, there are only one Node
// 		head = NULL;			  // therefore Head changes to NULL
// 	else						  // Before Node's Next Node changes to NULL
// 		prev_Node->setNextNode(NULL);
// 	// Return Deleted Node's Data by reference
// 	Data = Delete_Node->getData();
// 	delete Delete_Node; // Delete Node
// 	return true;		// Return Data
// }

int List::searchIndex(string searchString)
{
	if (head == NULL)
	{
		// cout << "There is no " << searchString << " Data Node" << endl;
		return -1;
	}
	else
	{
		char compare[10];
		strcpy(compare, searchString.c_str());

		int index = 0;
		int result = -1;
		Hangul *node = head;
		while (index == 0 || node != NULL)
		{

			if (strcmp(node->geteng(), compare) == 0)
			{
				result = index;
				break;
			}
			node = node->getNext();
			index++;
		}

		if (result == -1)
		{
			// cout << "There is no " << searchString << " Data Node" << endl;
			return -1;
		}
		else
		{
			// cout << searchString << " Data Node’s forward index is " << result << endl;
			return result;
		}
	}
}

int List::indexToUnicode(int index)
{
	if (head == NULL)
		return -1;
	else
	{
		Hangul *node = head;
		while (index != 0)
		{
			node = node->getNext();
			index--;
		}

		return node->getuni();
	}
}

void List::PrintList()
{								 // Print List
	if (head == NULL)			 // If List is empty
		cout << "Empty" << endl; // Print out Error Message
	else
	{
		Hangul *Print_Node = head;
		// cout << "Data : " ;
		while (Print_Node != NULL)
		{										// If Node is not NULL
			printHangul(Print_Node->getuni());	// Print out Node's data
			Print_Node = Print_Node->getNext(); // Move to Next Node
		}
		cout << endl;
	}
}

void List::PrintEngs()
{								 // Print List
	if (head == NULL)			 // If List is empty
		cout << "Empty" << endl; // Print out Error Message
	else
	{
		Hangul *Print_Node = head;
		char *temp;
		cout << "engs : ";
		while (Print_Node != NULL)
		{ // If Node is not NULL
			temp = Print_Node->geteng();
			cout << temp << endl;
			Print_Node = Print_Node->getNext(); // Move to Next Node
		}
		cout << endl;
	}
}