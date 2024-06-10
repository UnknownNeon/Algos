#include <iostream>
#include <vector>

#define p(x) std::cout << x << std::endl

template<typename T>
class queue {

int q_head, q_tail;
int max;
T* queue_ds;

    public :
    queue(int max): q_head(-1) , q_tail(-1){
        this->max = max;
        //queue_ds[max];
        queue_ds = (T*)malloc(sizeof(T) * max);
    }

    ~queue(){
        delete queue_ds;
    }

    void enqueue(T n){
        if(q_head == -1 && q_tail == -1){
            q_head = 0;
            q_tail = 0;
            queue_ds[q_tail] = n;
        }
        else if((q_tail+1)%max == q_head){
            std::cout << "Full queue" << std::endl;
        }
        else
        {
            q_tail = (q_tail+1)%max;
            queue_ds[q_tail] = n;
        }
    }



    T dequeue(){
       if((q_head == -1 && q_tail == -1)){
           std::cout << "Empty queue" << std::endl;
           //return -1;
       }
       else if((q_head == q_tail) && q_head != -1 && q_tail != -1 ){
        int temp = q_head;
        q_head = -1;
        q_tail = -1;
        return queue_ds[temp];
       }
       else{
        q_head = (q_head+1)%max;
        return queue_ds[(q_head-1)%max];
       }
    }

    void print_queue_state(){

        for(int i = 0 ; i < max ; i++){
            std::cout << queue_ds[i] << " --->" ;
        }
        std::cout << std::endl;
    }

    int size(){
        if(q_head == -1 && q_tail == -1 ){
            return 0;
        }
        else{
            if(q_tail < q_head){
                return (q_tail+(max - q_head))+1;
            }
            else{
                return (q_tail-q_head)+1;
            }
        }
    }
    
};

//Usage Note
int main(){

    queue<int> q(2);

    q.enqueue(22);
    p(q.dequeue());
    p("Done ");
    return 0;
}
