#include "RValueReference.h"
#include <iostream> 
using namespace std;

class Intvec {
public:
    explicit Intvec(size_t num = 0)
        : m_size(num), m_data(new int[m_size]) {
        log("constructor");
    }

    ~Intvec() {
        log("destructor");
        if (m_data) {
            delete[] m_data;
            m_data = 0;
        }
    }

    Intvec(const Intvec& other)
        : m_size(other.m_size), m_data(new int[m_size]) {
        log("copy constructor");
        for (size_t i = 0; i < m_size; ++i)
            m_data[i] = other.m_data[i];
    }

    Intvec& operator=(const Intvec& other) {
        log("copy assignment operator");
        Intvec tmp(other);
        std::swap(m_size, tmp.m_size);
        std::swap(m_data, tmp.m_data);
        return *this;
    }

    // if this is implemented, "v2 = Intvec(33);" will use this and prevents an extra temporary object by using a reference to an rvalue
    Intvec& operator=(Intvec&& other) {
        log("move assignment operator");
        std::swap(m_size, other.m_size);
        std::swap(m_data, other.m_data);
        return *this;
    }
    
private:
    void log(const char* msg) {
        cout << "[" << this << "] " << msg << "\n";
    }

    size_t m_size;
    int* m_data;
};


int RValueReference::RunExample() {
    std::cout << "### RValueReference Example:" << std::endl;

    Intvec v1(20);
    Intvec v2;
    cout << "assigning lvalue...\n";
    v2 = v1;
    cout << "ended assigning lvalue...\n";

    cout << "assigning rvalue...\n";
    v2 = Intvec(33);
    cout << "ended assigning rvalue...\n";

    return 0;
}

