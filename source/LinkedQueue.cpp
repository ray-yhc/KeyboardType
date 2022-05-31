#include "LinkedQueue.h"

void Queue::EnQueue(Hangul *Data)
{
	pushback(Data);
}
// bool Queue::DeQueue(string &Data)
// {
// 	return popfront(Data);
// }
void Queue::PrintQueue()
{
	PrintList();
}