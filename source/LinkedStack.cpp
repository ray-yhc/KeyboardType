#include "LinkedStack.h"

void Stack::Push(Hangul *Data)
{
	pushfront(Data);
}
bool Stack::Pop(char *Data)
{
	return popfront(Data);
}
void Stack::PrintStack()
{
	PrintList();
}
