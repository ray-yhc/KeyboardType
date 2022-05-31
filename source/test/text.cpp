#include <iostream>
// #include "LinkedQueue.h"
// #include "LinkedStack.h"
#include <string.h>
#include <stdio.h>
#pragma warning(disable : 4996)

using namespace std;

int printHangul(int, int, int);
int printHangul(int);

int main()
{

    printHangul(0xAC00);
    printHangul(0xAC10);
    printHangul(0xAC20);
    cout << endl;
    printHangul(0, 0, 0);
    printHangul(2, 0, 0);
    printHangul(3, 0, 0);
    cout << endl;

    cout << endl;
    // 초성
    string init = "rRseEfaqQtTdwWczxvg";
    // 중성
    string mid[] = {"k", "o", "i", "O", "j", "p", "u", "P", "h", "hk", "ho", "hl", "y", "n", "nj", "np", "nl", "b",
                    "m", "ml", "l"};
    // 종성
    string fin[] = {"r", "R", "rt", "s", "sw", "sg", "e", "f", "fr", "fa", "fq", "ft", "fx", "fv", "fg", "a", "q",
                    "qt", "t", "T", "d", "w", "c", "z", "x", "v", "g"};
    int index = -1;

    int unicodeSet[] = {0x3131, 0x3132, 0x3133, 0x3134, 0x3135,
                        0x3136, 0x3137, 0x3139, 0x313a,
                        0x313b, 0x313c, 0x313d, 0x313e, 0x313f,
                        0x3140, 0x3141, 0x3142, 0x3144,
                        0x3145, 0x3146, 0x3147, 0x3148,
                        0x314a, 0x314b, 0x314c, 0x314d, 0x314e,
                        0x314f, 0x3150, 0x3151, 0x3152, 0x3153};

    int uniCode = 0x3131;
    for (int i = 0; i < 27; i++)
    {
        uniCode = unicodeSet[i];
        printHangul(uniCode);
        cout << " " << fin[i] << " ";
        cout << showbase << internal << hex;
        cout << uniCode << endl;
    }

    // uniCode = 0x3131;
    // for (int i = 0; i < 35; i++)
    // {
    //     cout << showbase << internal << hex;
    //     cout << uniCode;
    //     cout << ", ";
    //     uniCode++;
    // }
    // cout << endl;
    // uniCode = 0x3131;
    // for (int i = 0; i < 35; i++)
    // {
    //     printHangul(uniCode);
    //     uniCode++;
    // }

    return 0;
    /////////////////////////////////

    // char hangul[3] = "0xAC00";

    // cout << hangul << endl;
    // cout << "\ue000" << endl;

    // string korean = "정윤성";
    // cout << korean[0] << korean[1] << korean[2] << "\n";
    // for (int i = 0; i < (int)korean.size(); i += 3)
    // {
    //     cout << korean.substr(i, 3);
    // }
    // return 0;

    char hangul[3];
    int cnt = 0;
    for (unsigned short i = 0xAC00; i <= 0xD7A3; i++)
    {
        // 참고
        // http://www.codeguru.com/cpp/misc/misc/multi-lingualsupport/article.php/c10451/The-Basics-of-UTF8.htm
        hangul[0] = ((char)(0xE0 | i >> 12));
        hangul[1] = ((char)(0x80 | i >> 6 & 0x3F));
        hangul[2] = ((char)(0x80 | i & 0x3F));
        // printf("%X = %c%c%c\n", i, hangul[0], hangul[1], hangul[2]);
        cout << hangul[0] << hangul[1] << hangul[2] << endl;
        // cout << hangul.substr(i, 3) << endl;
        ++cnt;
    }
    printf("cnt = %d\n", cnt);

    int initialIndex = 1, middleIndex = 3, finalIndex = 1;
    int result = 0xAC00 + initialIndex * 21 * 28 + middleIndex * 28 + finalIndex;
    hangul[0] = ((char)(0xE0 | result >> 12));
    hangul[1] = ((char)(0x80 | result >> 6 & 0x3F));
    hangul[2] = ((char)(0x80 | result & 0x3F));
    cout << hangul[0] << hangul[1] << hangul[2] << endl;

    return 0;
}

int printHangul(int initialIndex, int middleIndex, int finalIndex)
{
    char hangul[3];
    int result = 0xAC00 + initialIndex * 21 * 28 + middleIndex * 28 + finalIndex;
    hangul[0] = ((char)(0xE0 | result >> 12));
    hangul[1] = ((char)(0x80 | result >> 6 & 0x3F));
    hangul[2] = ((char)(0x80 | result & 0x3F));
    cout << hangul[0] << hangul[1] << hangul[2];

    return 0;
}

int printHangul(int uniCode)
{
    char hangul[3];
    hangul[0] = ((char)(0xE0 | uniCode >> 12));
    hangul[1] = ((char)(0x80 | uniCode >> 6 & 0x3F));
    hangul[2] = ((char)(0x80 | uniCode & 0x3F));
    cout << hangul[0] << hangul[1] << hangul[2];

    return 0;
}