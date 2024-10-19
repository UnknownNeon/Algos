// Work in progress

// This is to implement the strassens Matrix Multiplication algorithm
// Normal Matrix Multiplication casuses a time complexity of o(n3)
// Strassens Matrix Multiplication effeciency is O(n2.83)

/*
Definig a Small problem in Matrix multiplication Small(p):

1> if the Problem is 1 x 1
    ans : Direct Multiplication of the terms;
2> if the Problem is 2 x 2
    ans:

    |a  b|   |e  f|     | a`  b`|
    |    | * |    | =   |       |
    |c  d|   |g  h|     | c`  d`|

    a` = a*e + b*g;
    b` = a*f + b*h;
    c` = c*e + d*g;
    d` = c*f + d*h;


*/
#include <iostream>
#include <memory>

template <typename T, int Order>
class mat
{
    int size;
    T **ptr;
    void allocate()
    {
        this->ptr = (T **)malloc(sizeof(T) * size);
        for (int i = 0; i < size; i++)
        {
            *(this->ptr + i) = (T *)malloc(sizeof(T) * size);
            for (int j = 0; j < size; j++)
                *(*(this->ptr + i) + j) = *(*(this->ptr + i) + j) ^ *(*(this->ptr + i) + j); // XOR Operation to zero out mem
        }
    }

public:
    mat()
    {
        this->size = Order;
        this->allocate();
    }

    void re_allocate(size_t size)
    {

        if (size < this->size)
        {
            this->ptr = (T **)realloc(this->ptr, size);
            this->size = size;
            std::cout << "Reallocated -" << std::endl;
        }
        else if (size == this->size)
        {
            std::cout << "Already at size" << std::endl;
        }
        else
        {
            this->ptr = (T **)realloc(this->ptr, size);
            for (int i = this->size; i < size; i++)
            {
                *(this->ptr + i) = (T *)malloc(sizeof(T) * size);
                // Zeroing out the mem here
                for (int j = 0; j < size; j++)
                    *(*(this->ptr + i) + j) = *(*(this->ptr + i) + j) ^ *(*(this->ptr + i) + j); // XOR Operation to zero out mem
            }
            std::cout << "Reallocated +" << std::endl;
        }
    }
    inline T **data() { return this->ptr; }
    inline int getSize() { return this->size; }
};

int main()
{
    mat<int, 4> mat_1;
    mat<int, 4> mat_2;
    mat<int, 4> result;
    algorithm(mat_1.data(), mat_2.data(), 4, result.data());
}

void algorithm(int **a, int **b, int size, int **result)
{
    if (size <= 2)
    {
        result[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
        result[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
        result[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
        result[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
    }
}