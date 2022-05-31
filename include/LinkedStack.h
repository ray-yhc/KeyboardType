#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "LinkedList.h"

class Stack : public List
{
public:
	void Push(Hangul *);
	bool Pop(string &);
	void PrintStack();
};
#endif