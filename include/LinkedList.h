#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Hangul.h"
class List
{
private:
	string name;
	Hangul *head; // Pointer for First Node
public:
	List(string _name); // Constructor
	List();
	~List(); // Destructor
	string getListName();
	void pushfront(Hangul *_hangul); // Insert Data to List at front
	void pushback(Hangul *_hangul);	 // Insert Data to List at back
	bool popfront(char *Data);		 // Delete Data fromt List at front
	bool popback(char *Data);		 // Delete Data fromt List at back
	int searchIndex(string searchString);
	int indexToUnicode(int index);
	void PrintList(); // Print List
	void PrintEngs();
};
#endif