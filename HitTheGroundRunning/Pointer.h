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
    void changePointerRef(int *& intptr);
    void changePointerValue(int * intptr);
    int RunExample() override;
};

