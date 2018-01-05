#include "Adapter.h"
#include "Builder.h"
#include "Set.h"

#include <iostream>

int main() {


    std::cout << "###### Pattern Examples" << std::endl;
    // run patterns examples
    Adapter* adapter_ptr = new Adapter();
    adapter_ptr->RunExample();
    delete adapter_ptr;
    Builder* builder_ptr = new Builder();
    builder_ptr->RunExample();
    delete builder_ptr;

    std::cout << "###### STL Examples" << std::endl;
    // run STL examples
    Set* set_ptr = new Set();
    set_ptr->RunExample();
    delete set_ptr;



    return 0;
}