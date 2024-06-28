//Just some operator overloading concepts with pointers ..

#ifndef BASIC_IO

#include <iostream>

#define BASIC_IO
#endif

#ifndef ARRAYS
#define ARRAYS

#include <malloc.h>

template<typename T ,int a>
class Array {
    protected:
    T* f_1;
    T* f_2;
};

template<typename T ,int a>
class Array1D : protected Array<T,a> {

public:
    Array1D() {
        this->f_1 = (T*) malloc(sizeof(T) * a);
    }

    T& operator[](int foo){
        if( foo <= a )
        return *(this->f_1 + (sizeof(T) * foo));
    }

    T operator=(T data){
        return data;
    }
};

#endif

// use
// # include <arrays.hpp>

// int main(){
//     Array1D<const char*,10> a;
//     a[1] = "Hellow";
//     a[10] = "Wworlds";
//     std::cout << a[1] << a[10] <<std::endl;
// }
