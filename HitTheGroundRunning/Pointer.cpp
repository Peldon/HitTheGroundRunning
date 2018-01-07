#include "Pointer.h"
#include <iostream> 
using namespace std;

// see also https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp4_PointerReference.html

int Pointer::squareConst(const int number) {
    // number *= number;  // error: assignment of read-only parameter
    return number * number;
}

int Pointer::squareNonConst(int number) {  // non-const parameter
    number *= number;
    return number;
}

int Pointer::squareConstRef(const int & number) {  // const reference
    return number * number;
}

int Pointer::squareNonConstRef(int & number) {  // non-const reference
    return number * number;
}

void Pointer::changePointer(int * intptr) {
    int i = 5;
    cout << "inside before: " << intptr << endl;
    intptr = &i;
    cout << "inside after: " << intptr << endl;

}

int Pointer::RunExample() {
    std::cout << "### Pointer Example:" << std::endl;

    int number = 88;     // An int variable with a value
    int * pNumber;       // Declare a pointer variable called pNumber pointing to an int (or int pointer)
    pNumber = &number;   // Assign the address of the variable number to pointer pNumber
    int * pAnother = &number; // Declare another int pointer and init to address of the variable number

    int & refNumber = number; // Declare a reference (alias) to the variable number
                              // Both refNumber and number refer to the same value

    cout << pNumber << endl;  // Print content of pNumber (0x22ccf0)
    cout << &number << endl;  // Print address of number (0x22ccf0)
    cout << *pNumber << endl; // Print value pointed to by pNumber (88)
    cout << number << endl;   // Print value of number (88)

    *pNumber = 99;            // Re-assign value pointed to by pNumber
    cout << pNumber << endl;  // Print content of pNumber (0x22ccf0)
    cout << &number << endl;  // Print address of number (0x22ccf0)
    cout << *pNumber << endl; // Print value pointed to by pNumber (99)
    cout << number << endl;   // Print value of number (99)
                              // The value of number changes via pointer

    cout << &pNumber << endl; // Print the address of pointer variable pNumber (0x22ccec)

    // not initialized / null
    int * pUninitialized; // points to undefined, cannot be used until initialized
    //cout << "Uninit pointer: " << pUninitialized << endl; // error!
    pUninitialized = 0; // = NULL = nullptr ? points to nothing
    cout << "nullpointer: " << pUninitialized << endl;
    //int & refUninitialized; //error, because a ref is static and must be initialized

    const int constNumber = 9;
    cout << squareConst(number) << endl;
    cout << squareConst(constNumber) << endl;
    cout << squareNonConst(number) << endl;
    cout << squareNonConst(constNumber) << endl;

    cout << squareConstRef(number) << endl;
    cout << squareConstRef(constNumber) << endl;
    cout << squareNonConstRef(number) << endl;
    // cout << squareNonConstRef(constNumber) << endl;


    int i1 = 8, i2 = 9;
    const int * iptr1 = &i1; // non-constant pointer pointing to constant data
    int * const iptr2 = &i1;  // constant pointer pointing to non-constant data
    const int * const iptr3 = &i1;  // constant pointer pointing to constant data
    // *iptr3 = 9;   // error: assignment of read-only variable
    // iptr3 = &i2;  // error: assignment of read-only variable


    cout << "before: " << pNumber << endl;
    changePointer(pNumber);
    cout << "after: " << pNumber << endl;
    // of course this changes the pointer content only inside the function, because the pointer itself is passed as value and does not change the pointer outside

    return 0;
}
