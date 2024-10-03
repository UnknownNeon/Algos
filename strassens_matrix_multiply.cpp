// Work in progress

// This is to implement the strassens Matrix Multiplication algorithm
// Normal Matrix Multiplication casuses a time complexity of o(n3)
// Strassens Matrix Multiplication effeciency is O(n2.83)

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
};

int main()
{
    mat<int, 2> mat;

    mat.data()[0][0] = 1;
    mat.data()[0][1] = 2;
    mat.data()[1][0] = 3;
    mat.data()[1][1] = 4;

    mat.re_allocate(3);
    mat.data()[2][0] = 5;

    std::cout << mat.data()[2][0] << std::endl;
}
