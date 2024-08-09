//Hexdump in little Endian


#include <iostream>
#include<fstream>

int main(int argc , char* argv[] ){

    std::ifstream file((const char*)argv[1], std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    unsigned short hex;
    while (file.read((char *)&hex, 2)) { 
        hex = (hex << 8) | (hex >> 8) ;
        if(hex == 0){
            std::cout << "00 \t";
        }
        else{
        std::cout << std::hex << (hex >> 8);
        std::cout << " \t";
        std::cout << std::hex << (hex & 0x00ff);
        std::cout << " \t";
        }
        
      
    }
    file.close();
    return 0;
}