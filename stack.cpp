#include <iostream>
#include <vector>

#define p(x) std::cout<< x << std::endl

template<typename T>
class stack {
    int max;
    int top;
    T* stack_ds;

public:
    stack(T size_of_stack) : max(0) , top(-1){
        this->max = size_of_stack;
        stack_ds = (T*) malloc(sizeof(T) * size_of_stack);
    }

    void push(T n){
        if(top+1 == max){
            std::cout << "Stack full" << std::endl;
        }
        else{
            top++;
            stack_ds[top] = n;
        }
    }

    T pop(){
        if( top == -1 ){
            std::cout << "Stack empty" << std::endl;
            return T{};
        }
        else if(top == 0){
            top = -1;
            return stack_ds[0];
        }
        else{
            int temp = top;
            top--;
            return stack_ds[temp];
        }
    }

    inline int size(){
        return top+1;
    }

    void print_stack_state(){

        for(int i = 0 ; i < max ; i++){
            std::cout << stack_ds[i] << " --->" ;
        }
        std::cout << std::endl;
    }

};

int main(){
    
    stack<int> s(5);

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s.push(6);
    s.push(7);
    s.push(8);

    p(s.pop());
    p(s.pop());
    p(s.pop());
    p(s.pop());
    p(s.pop());

    p(s.pop());
    p(s.pop());
    p(s.pop());

    return 0;
}