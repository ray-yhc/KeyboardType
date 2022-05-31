#include "Hangul.h"
#include <string.h>
#include <iostream>
#pragma warning(disable : 4996)

Hangul ::Hangul(const char *_eng, int _uni)
{
    strcpy(eng, _eng);
    this->uni = _uni;
}

Hangul ::~Hangul()
{
}
int Hangul ::compare(const char c[3])
{
    if (strcmp(c, eng) == 0)
        return 1;
    else
        return 0;
}
char *Hangul ::geteng()
{
    return eng;
}
int Hangul ::getuni()
{
    return uni;
}
Hangul *Hangul ::getNext()
{
    return next;
}
void Hangul ::setNext(Hangul *_hangul)
{
    this->next = _hangul;
}

int printHangul(int initialIndex, int middleIndex, int finalIndex)
{
    // 수정필요 : 에러처리 정확하게
    // index가 -1일경우 재조정
    if (initialIndex == -1)
        initialIndex = 0;
    if (middleIndex == -1)
        middleIndex = 0;
    if (finalIndex == -1)
        finalIndex = 0;
    else
        finalIndex++;

    char hangul[3];
    // 유니코드 생성
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

// class Pokemon
// {
// protected:
//     int pokemonId;
//     char *pokemonName;
//     double height;
//     double weight;
//     char *pokemonType;
//     char **pokemonImage;
//     int img_width;
//     int img_height;

//     Pokemon *next;

// public:
//     static int totalPokemon;
//     Pokemon(int _ID, const char *_pokemonName, double _height, double _weight, const char *_pokemonType);
//     ~Pokemon();
//     int set_pokemonimage(string _filename);
//     int print();
//     int compare_name(const char *_pokemonName);
//     int showpokemon();
//     char *get_name();
//     Pokemon *get_next();
//     int set_next(Pokemon *_next);
// };

// class List
// {
// private:
//     Pokemon *head;

// public:
//     List();
//     ~List();
//     Pokemon *search_pokemon(const char *_itemName);
//     int insert_pokemon(Pokemon *_pokemon);
//     int delete_pokemon(Pokemon *_pokemon);
//     int print_pokemons();
// };
