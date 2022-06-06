#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "LinkedList.h"

class Stack : public List
{
public:
	void Push(Hangul *);
	bool Pop(char *Data);
	void PrintStack();
};
#endif