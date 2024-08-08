//Hexdump in Big Endian
//@TODO : Small endian 

#include <iostream>
#include<fstream>

int main(int argc , char* argv[] ){

    std::ifstream file((const char*)argv[1], std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    short hex;
    while (file.read((char *)&hex, 2)) { 
        std::cout << std::hex << hex;
        std::cout << "\t";
      
    }
    
    file.close();
    return 0;
}