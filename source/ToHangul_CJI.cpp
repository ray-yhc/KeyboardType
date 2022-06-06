#include <string.h>
#include "ToHangul_CJI.h"
#pragma warning(disable : 4996)

using namespace std;

void cjiShift(CJITree cjitree, Stack &hangulstack, int signal)
{
    char *temp, *out;
    Hangul *newHangul;
    // string tempStr;
    // hangulstack.Pop(temp);
    // cout << temp << endl;
    // out = cjitree.Search(signal, tempStr.c_str());
    out = cjitree.Search(signal, "r");
    if (out != NULL)
    {
        cout << out << endl;
        newHangul = new Hangul(out, 0);
        hangulstack.Push(newHangul);
    }

    cout << "endshift" << endl;

    // Search(int _signal, const char* input);
}