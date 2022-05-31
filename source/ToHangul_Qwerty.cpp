#include <iostream>
#include "LinkedList.h"
#include <string.h>
#include "ToHangul_Qwerty.h"
#pragma warning(disable : 4996)

using namespace std;

int getIndex(List *dataset, string &c)
{
    int index = -1;
    index = dataset->searchIndex(c);
    return index;
}

string QwertytoHangul(struct HangulSet &hangulset, string &inputText)
{
    int initialIndex = 0, middleIndex = 0, finalIndex = 0;
    int tempMiddleIndex, tempFinalIndex;

    string searchChar;
    searchChar.reserve(10);

    for (int i = 0; i < inputText.length();)
    {
        // if 한글이 아니면 그대로 출력하고 패스
        if (!isalpha(inputText[i]))
        {
            cout << inputText[i];
            i++;
            continue;
        }

        // 초성인덱스 추출
        searchChar = inputText.substr(i, 1);
        initialIndex = getIndex(hangulset.chosung, searchChar);
        i++;

        // 중성인덱스 추출
        // 합성모음 추출
        tempMiddleIndex = -1;
        if ((i + 2) <= inputText.length())
        {
            searchChar = inputText.substr(i, 2);
            tempMiddleIndex = getIndex(hangulset.jungsung, searchChar);
        }

        // 합성모음인지 확인하고 단일모음 추출
        if (tempMiddleIndex != -1)
        {
            middleIndex = tempMiddleIndex;
            i += 2;
        }
        else
        {
            if ((i + 1) <= inputText.length())
            {
                searchChar = inputText.substr(i, 1);
                middleIndex = getIndex(hangulset.jungsung, searchChar);
                i++;
            }
        }

        if (middleIndex == -1)
        {
            int uni;
            // i--;
            uni = hangulset.chosung->indexToUnicode(initialIndex);
            if (uni != -1)
            {
                printHangul(uni);
            }
            else
                ;
            // cout << inputText[i - 1]; //출력한다
            // inputText[i-1] 의 유니코드 찾아서 printHangul(uniCode)
            // initialIndex  번째의 유니코드 찾아서 printHangul(uniCode)
            i++;
            continue;
        }

        // 종성인덱스 추출
        // 합성종성 추출
        tempFinalIndex = -1;
        if ((i + 2) <= inputText.length())
        {
            searchChar = inputText.substr(i, 2);
            tempFinalIndex = getIndex(hangulset.jongsung, searchChar);
        }

        // 합성종성인지 확인하고 단일종성 추출
        if (tempFinalIndex != -1)
        {
            finalIndex = tempFinalIndex;
            i += 2;
        }
        else
        {
            if ((i + 1) <= inputText.length())
            {
                searchChar = inputText.substr(i, 1);
                finalIndex = getIndex(hangulset.jongsung, searchChar);
                i++;
            }
            else
                cout << inputText[i];
        }

        // 초성인지 종성인지 체크
        if (finalIndex != -1 && i < inputText.length())
        {
            searchChar = inputText.substr(i, 1);
            tempMiddleIndex = getIndex(hangulset.jungsung, searchChar);
            if (tempMiddleIndex != -1)
            {
                finalIndex = -1;
                i--;
            }
        }

        //한글 출력
        printHangul(initialIndex, middleIndex, finalIndex);
    }
    cout << endl;

    string result = "imsii";
    // cout << result << endl;
    return result;
}