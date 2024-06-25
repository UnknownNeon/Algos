#include <iostream>
#include <fstream>

template<typename T>
class Serialize {

const char* filepath_persistent;

public:
    Serialize(T data , const char* path){
        this->filepath_persistent = path;

        std::fstream f;
        f.open(path, std::ios::out | std::ios::binary);

        if(f.is_open()){
            f.write(reinterpret_cast<char*>(&data),sizeof(T));
        }

        f.close();
    }

    T deserialize(){

        T data;
        std::fstream f;

        f.open(this->filepath_persistent, std::ios::in | std::ios::binary);

        if(f.is_open()){
            f.read(reinterpret_cast<char*>(&data),sizeof(T));
        }

        f.close();
        return data;
    }

    ~Serialize(){
        filepath_persistent = "";
    }
};

//Usage

// int main(){

//     Serialize<const char*> s("Hellow world" , "./hellow.dat");
//     const char* d = s.deserialize();

//     std::cout << d <<std::endl;
//     return 0;
// }