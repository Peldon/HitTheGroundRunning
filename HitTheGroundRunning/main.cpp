#include "Pointer.h"
#include "RValueReference.h"
#include "Adapter.h"
#include "Builder.h"
#include "Set.h"

#include <iostream>

int main() {

    Example* e_ptr;

    // run Basics examples
    std::cout << "###### Basics Examples" << std::endl;
    e_ptr = new Pointer();
    e_ptr->RunExample();
    delete e_ptr;
    e_ptr = new RValueReference();
    e_ptr->RunExample();
    delete e_ptr;

    // run patterns examples
    std::cout << "###### Pattern Examples" << std::endl;
    e_ptr = new Adapter();
    e_ptr->RunExample();
    delete e_ptr;
    e_ptr = new Builder();
    e_ptr->RunExample();
    delete e_ptr;

    // run STL examples
    std::cout << "###### STL Examples" << std::endl;
    e_ptr = new Set();
    e_ptr->RunExample();
    delete e_ptr;

    return 0;
}