#ifndef QUERTY_H
#define QUERTY_H
#include "LinkedList.h"
#include <string.h>

struct HangulSet
{
    List *chosung;
    List *jungsung;
    List *jongsung;
};

int getIndex(List *dataset, string &c);
string QwertytoHangul(struct HangulSet &hangulset, string &inputText);

#endif