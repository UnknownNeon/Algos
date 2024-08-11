//incomplete,,, need implementing padding

#include <iostream>
#include <string>
 
namespace base64{
const char table[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
        'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
        'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        '+', '/'
    };
const char* padding = "=";
}
 
int main(int argc , char * argv[]){
 
std::string text(argv[1]);
 
 
int inc_l = 0;
int counter = 0 ;
unsigned char byte , tbyte; 
 
 
while(counter <= text.length()){
 
switch (inc_l)
    {
        case 0:
                byte = text[counter];
                byte = base64::table[byte >> 2];
                inc_l += 2;
                std::cout << byte ;
                break;
        case 2:
                byte = text[counter];
                tbyte = byte & 0b00000011;
                byte = text[counter+1];
                byte = (byte >> inc_l) | (tbyte << 6);
                byte = base64::table[byte >> 2];           
                inc_l += 2;

                counter++;

                std::cout << byte ;
                break;
        case 4:
                byte = text[counter];
                tbyte = byte & 0b00001111;
                byte = text[counter+1];
                byte = (byte >> inc_l) | (tbyte << 4) ;
                byte = base64::table[byte >> 2];
                inc_l += 2;
                counter++;
                std::cout << byte ;
 
                break;
        case 6:
                byte = text[counter];
                tbyte = byte & 0b00111111;
                byte = base64::table[tbyte];
                inc_l += 2;
                std::cout << byte ;
 
                break;
        case 8:

                 counter++;
                 inc_l = 0;
    }
 
}
 
} 