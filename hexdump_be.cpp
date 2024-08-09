//Hexdump in little Endian


#include <iostream>
#include<fstream>

int main(int argc , char* argv[] ){

    std::ifstream file((const char*)argv[1], std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    int count = 0 ;
    unsigned short hex;
    while (file.read((char *)&hex, 2)) { 

        if(count == 5){
            count = 0;
            std::cout << std::endl;
        }
        hex = (hex << 8) | (hex >> 8) ;
        if(hex == 0){
            std::cout << "0\t0\t";
        }
        else{
        std::cout << std::hex << (hex >> 8) << "\t";
        std::cout << std::hex << (hex & 0x00ff) << "\t";
        }
        count ++;
    }
    file.close();
    return 0;
}