#pragma once
#include "Example.h"
class Pointer :
    public Example {
public:
    int squareConst(const int number);
    int squareNonConst(int number);
    int squareConstRef(const int & number);
    int squareNonConstRef(int & number);
    void changePointer(int * intptr);
    int RunExample() override;
};

