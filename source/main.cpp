#include <iostream>
#include <stdio.h>
// #include "LinkedList.h"
#include "LinkedQueue.h"
#include "LinkedStack.h"
#include <string.h>
#include <fstream>
#include "ToHangul_Qwerty.h"
#include "ToHangul_CJI.h"
#include "NumStack.h"
#include "CJITree.h"
#pragma warning(disable : 4996)

using namespace std;

string CJItoHangul(CJITree &cjitree, int cji[], int length);

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
        char _input[3];
        char _output[3];
        int _signal;
        while (fscanf(file, "%d %s %s\n", &_signal, _input, _output) != EOF)
        {
            node = new cjiNode(_signal, _input, _output);
            cjitree.Insert(node);
            // cout << "Insert [" << _signal << "|" << _input << "|" << _output << "]" << endl;
        }
        cout << "---------------------------------------------------------------" << endl;
        cout << "데이터 불러오기에 성공했습니다." << endl;
        cjitree.printTree(cjitree.getRoot());
        cout << endl;
    }
    else
    {
        cout << "데이터 불러오기에 실패했습니다." << endl;
    }
    fclose(file);

    // int cji[] = {0, 12, 5, 10, 5, 2, 2, 10, 8, 8, 12, 8, 2, 11, 0, 2, 2, 3, 12};
    // int cji[] = {1, 1, 1, 1, 2, 5};
    int cji[] = {4, 4, 4, 1};
    // result = QwertytoHangul(hangulset, eng);
    string hangul_cji = CJItoHangul(cjitree, cji, (sizeof(cji) / sizeof(cji[0])));

    // while (1)
    // {
    //     // 계속 문자 입력받기
    //     // stack에 추가, 문자 입력
    // }

    return 0;
}

string CJItoHangul(CJITree &cjitree, int cji[], int length)
{
    Stack hangulstack;
    NumStack numstack;
    int popNum;

    // 임시

    char *out;

    // cout << 1 << " 번째 ====================" << endl; // flag
    // cjitree.printTree(cjitree.getRoot());
    // out = cjitree.Search(4, "r");
    // cout << out << endl;
    // cout << 2 << " 번째 ====================" << endl; // flag
    // cjitree.printTree(cjitree.getRoot());
    // out = cjitree.Search(4, "r");
    // cout << out << endl;
    // cout << 3 << " 번째 ====================" << endl; // flag
    // cjitree.printTree(cjitree.getRoot());
    // out = cjitree.Search(1, "k");
    // if (out != NULL)
    //     cout << out << endl;

    Hangul *newHangul;

    char *temp;
    newHangul = new Hangul("r", 0);
    hangulstack.Push(newHangul);
    cout << hangulstack.Pop(temp) << endl;
    cout << "pop completed: " << temp << endl;
    newHangul = new Hangul("r", 0);
    hangulstack.Push(newHangul);
    hangulstack.PrintEngs();

    // 임시

    for (int i = 0; i < length;)
    {

        cout << i << " 번째 ====================" << endl; // flag
        switch (cji[i])
        {
        case 1:                                // ㅣ
        case 2:                                // ᆞ
        case 3:                                // ㅡ
            cout << cji[i] << " 모음" << endl; // flag
            popNum = numstack.getHead();
            cout << popNum << endl; // flag
            if (popNum == -1 || popNum == 1 || popNum == 2 || popNum == 3)
            {
                numstack.Push(cji[i]);
                cout << "push " << cji[i] << endl; // flags
            }
            else
            {
                // cjiShift(&hangulstack, &numstack){

                while (numstack.Pop(popNum))
                {
                    // char *temp;
                    char *output;
                    // Hangul *newHangul;

                    cout << "CJItoHangul - "
                         << popNum
                         << "shift ===================="
                         << endl;
                    // cout << cjitree.getRoot()->getinput() << endl;
                    // cjitree.printTree(cjitree.getRoot());
                    // cjiShift(cjitree, hangulstack, popNum);
                    if (hangulstack.Pop(temp))
                    {
                        cout << temp << endl;
                        output = cjitree.Search(popNum, temp);
                        if (output != NULL)
                        {
                            cout << output << endl;
                            newHangul = new Hangul(output, 0);
                            hangulstack.Push(newHangul);
                        }
                        else
                        {
                            cout << "pass" << endl;
                        }

                        hangulstack.PrintEngs();
                    }
                    else
                    {
                        // output = cjitree.Search(popNum, "_");
                        // if (output != NULL)
                        // {
                        //     cout << output << endl;
                        //     newHangul = new Hangul(output, 0);
                        //     hangulstack.Push(newHangul);
                        // }
                        // else
                        // {
                        // }
                    }
                }
                numstack.Push(cji[i]);
                cout << "push " << cji[i] << endl; // flag

                // }
            }
            //     //입력받기 중지, 자음 완성한다
            break;
        case 0: // ㅇㅁ
        case 4: // ㄱㅋㄲ
        case 5: // ㄴㄹ
        case 6: // ㄷㅌㄸ
        case 7: // ㅂㅍㅃ
        case 8: // ㅅㅎㅆ
        case 9: // ㅈㅊㅉ
            cout << cji[i] << " 자음" << endl;
            popNum = numstack.getHead();
            if (popNum == -1 || popNum == cji[i])
            {
                numstack.Push(cji[i]);
                cout << "push " << cji[i] << endl; // flag
                numstack.PrintStack();             // flag
            }
            else
            {
                // cjiShift(&hangulstack, &numstack){
                while (numstack.Pop(popNum))
                {
                }

                // }
            }

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

    // cout << endl
    //      << endl;
    // int imsi;
    // numstack.PrintStack();
    // numstack.Pop(imsi);
    // cout << imsi << endl;
    // numstack.Pop(imsi);
    // cout << imsi << endl;
    // numstack.Pop(imsi);
    // cout << imsi << endl;
    // numstack.Pop(imsi);
    // cout << imsi << endl;
    // numstack.PrintStack();
    // cout << endl
    //      << endl;

    string result = "imsii";
    // cout << result << endl;
    return result;
}