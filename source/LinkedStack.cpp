#include "LinkedStack.h"

void Stack::Push(Hangul *Data)
{
	pushback(Data);
}
// bool Stack::Pop(string &Data)
// {
// 	return popback(Data);
// }
void Stack::PrintStack()
{
	PrintList();
}
