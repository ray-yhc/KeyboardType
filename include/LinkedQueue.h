#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "LinkedList.h"

class Queue : public List
{
public:
	void EnQueue(Hangul *);
	bool DeQueue(string &);
	void PrintQueue();
};
#endif