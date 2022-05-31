#ifndef __IOSTREAM__
#define __IOSTREAM__
#include <iostream>
using namespace std;
#endif

#ifndef __HANGUL_H__
#define __HANGUL_H__

class Hangul
{
protected:
    char eng[3];
    int uni;

    Hangul *next;

public:
    Hangul(const char *_eng, int _uni);
    ~Hangul();
    int compare(const char c[3]);  //맞는 글자인지 검색
    char *geteng();                // eng 반환
    int getuni();                  // uni 반환
    Hangul *getNext();             //다음노드 반환
    void setNext(Hangul *_hangul); //다음노드 설정
};

int printHangul(int initialIndex, int middleIndex, int finalIndex);
int printHangul(int uniCode);
#endif