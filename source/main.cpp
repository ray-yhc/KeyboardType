#include <iostream>
#include <stdio.h>
// #include "LinkedList.h"
#include "LinkedQueue.h"
#include "LinkedStack.h"
#include <string.h>
#include <fstream>
#include "ToHangul_Qwerty.h"
#include "NumStack.h"
#include "CJITree.h"
#pragma warning(disable : 4996)

using namespace std;

string CJItoHangul(struct HangulSet &hangulset, int cji[], int length);

int main()
{
    // 초성 중성 종성 리스트 만들기
    // 리스트 하나로 묶어서 포인터
    struct HangulSet hangulset;
    char _name[100];
    char _eng[3];
    int _uni;

    // 초성 데이터 불러오기
    cout << "===============================================================" << endl;
    cout << "초성 데이터를 불러옵니다" << endl;
    FILE *file = fopen("./dataset/chosung.txt", "rt");
    if (file != NULL)
    {
        hangulset.chosung = new List("chosung");
        Hangul *hangul = NULL;

        while (fscanf(file, "%s %s %x\n", _name, _eng, &_uni) != EOF)
        {
            hangul = new Hangul(_eng, _uni);
            hangulset.chosung->pushback(hangul);
            // cout << "Insert [" << _name << "|" << _eng << "|" << _uni << "]" << endl;
        }
        cout << "---------------------------------------------------------------" << endl;
        cout << "데이터 불러오기에 성공했습니다." << endl;
        cout << hangulset.chosung->getListName() << " 리스트 출력 : ";
        hangulset.chosung->PrintList();
        cout << endl;
    }
    else
    {
        cout << "데이터 불러오기에 실패했습니다." << endl;
    }
    fclose(file);

    cout << "===============================================================" << endl;
    cout << "중성 데이터를 불러옵니다" << endl;
    file = fopen("./dataset/jungsung.txt", "rt");
    if (file != NULL)
    {
        hangulset.jungsung = new List("jungsung");
        Hangul *hangul = NULL;

        while (fscanf(file, "%s %s %x\n", _name, _eng, &_uni) != EOF)
        {
            hangul = new Hangul(_eng, _uni);
            hangulset.jungsung->pushback(hangul);
            // cout << "Insert [" << _name << "|" << _eng << "|" << _uni << "]" << endl;
        }
        cout << "---------------------------------------------------------------" << endl;
        cout << "데이터 불러오기에 성공했습니다." << endl;
        cout << hangulset.jungsung->getListName() << " 리스트 출력 : ";
        hangulset.jungsung->PrintList();
        cout << endl;
    }
    else
    {
        cout << "데이터 불러오기에 실패했습니다." << endl;
    }
    fclose(file);

    cout << "===============================================================" << endl;
    cout << "종성 데이터를 불러옵니다" << endl;
    file = fopen("./dataset/jongsung.txt", "rt");
    if (file != NULL)
    {
        hangulset.jongsung = new List("jongsung");
        Hangul *hangul = NULL;

        while (fscanf(file, "%s %s %x\n", _name, _eng, &_uni) != EOF)
        {
            hangul = new Hangul(_eng, _uni);
            hangulset.jongsung->pushback(hangul);
            // cout << "Insert [" << _name << "|" << _eng << "|" << _uni << "]" << endl;
        }
        cout << "---------------------------------------------------------------" << endl;
        cout << "데이터 불러오기에 성공했습니다." << endl;
        cout << hangulset.jongsung->getListName() << " 리스트 출력 : ";
        hangulset.jongsung->PrintList();
        cout << endl;
    }
    else
    {
        cout << "데이터 불러오기에 실패했습니다." << endl;
    }
    fclose(file);

    cout << "===============================================================" << endl
         << endl
         << endl;

    // string eng = ("dkssudgktpdy");
    string eng = ("qkfrdmsqlcdmfEkfktj!!!...!!");
    string hangul_qt = QwertytoHangul(hangulset, eng); // 리스트 묶음 포인터 전달

    //
    //
    //
    //
    //

    // 천지인 데이터 불러오기
    cout << "===============================================================" << endl;
    cout << "천지인 데이터를 불러옵니다" << endl;
    file = fopen("./dataset/cjiShift.txt", "rt");
    CJITree cjitree;
    if (file != NULL)
    {
        cjiNode *node = NULL;
        char _input[3], _output[3];
        int _signal;
        while (fscanf(file, "%d,%s,%s\n", _signal, _input, &_output) != EOF)
        {
            node = new cjiNode(_signal, _input, _output);
            cjitree.pushback(node);
            // cout << "Insert [" << _name << "|" << _eng << "|" << _uni << "]" << endl;
        }
        cout << "---------------------------------------------------------------" << endl;
        cout << "데이터 불러오기에 성공했습니다." << endl;
        cjitree.PrintList();
        cout << endl;
    }
    else
    {
        cout << "데이터 불러오기에 실패했습니다." << endl;
    }
    fclose(file);

    int cji[] = {0, 12, 5, 10, 5, 2, 2, 10, 8, 8, 12, 8, 2, 11, 0, 2, 2, 3, 12};
    // result = QwertytoHangul(hangulset, eng);
    string hangul_cji = CJItoHangul(hangulset, cji, (sizeof(cji) / sizeof(cji[0])));

    // while (1)
    // {
    //     // 계속 문자 입력받기
    //     // stack에 추가, 문자 입력
    // }

    return 0;
}

string CJItoHangul(struct HangulSet &hangulset, int cji[], int length)
{
    Stack hangulstack;
    NumStack numstack;
    int popNum;
    for (int i = 0; i < length;)
    {
        switch (cji[i])
        {
        case 1: // ㅣ
        case 2: // ᆞ
        case 3: // ㅡ
            popNum = numstack.getHead();
            if (popNum == 1 || popNum == 2 || popNum == 3)
            {
                numstack.Push(cji[i]);
            }
            else
            {
                // cjiShift(&hangulstack, &numstack){
                while (numstack.Pop(popNum))
                {
                }

                // }
            }
            cout << cji[i] << " 모음" << endl;
            //     //입력받기 중지, 자음 완성한다
            break;
        case 0: // ㅇㅁ
        case 4: // ㄱㅋㄲ
        case 5: // ㄴㄹ
        case 6: // ㄷㅌㄸ
        case 7: // ㅂㅍㅃ
        case 8: // ㅅㅎㅆ
        case 9: // ㅈㅊㅉ
            if (numstack.getHead() == cji[i])
            {
                numstack.Push(cji[i]);
            }
            else
            {
                // cjiShift(&hangulstack, &numstack){
                while (numstack.Pop(popNum))
                {
                }

                // }
            }

            cout << cji[i] << " 자음" << endl;

            // index = dataset->searchIndex(cji[i]);
            //     //계속 받는다
            break;
        case 10: // spacebar
        case 11: // backspace
        case 12: // enter
            cout << cji[i] << " 특수" << endl;
            //     //그냥 내보내거나 명령 수행한다.
            //     //단어를 끊는다
            break;
        default:
            cout << "잘못된 입력입니다." << endl;
            break;
        }
        i++;
    }

    cout << endl
         << endl;
    int imsi;
    numstack.PrintStack();
    numstack.Pop(imsi);
    cout << imsi << endl;
    numstack.Pop(imsi);
    cout << imsi << endl;
    numstack.Pop(imsi);
    cout << imsi << endl;
    numstack.Pop(imsi);
    cout << imsi << endl;
    numstack.PrintStack();
    cout << endl
         << endl;

    string result = "imsii";
    // cout << result << endl;
    return result;
}