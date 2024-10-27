
#include <iostream>
#include <string>
#include <unordered_map>

namespace base64
{
    const char table[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
        'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
        'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        '/', '+'};
    const char *padding = "=";
}

int main(int argc, char *argv[])
{
    std::unordered_map<char, int> map;

    // Mapping the base64 list
    for (int i = 0; i < 64; i++)
    {
        map[base64::table[i]] = i;
    }

    std::string text(argv[1]);

    int inc_l = 0;
    int counter = 0;
    unsigned char byte, tbyte;

    while (counter < text.length())
    {
        switch (inc_l)
        {
        case 0:
            byte = map[text[counter]];
            byte = byte << 2;
            tbyte = map[text[counter + 1]] >> 4;
            byte = byte | tbyte;
            std::cout << byte;
            counter++;
            inc_l += 2;

            break;
        case 2:
            byte = map[text[counter]];
            byte = byte << 4;
            tbyte = map[text[counter + 1]] >> 2;
            byte = byte | tbyte;
            std::cout << byte;
            counter++;
            inc_l += 2;

            break;
        case 4:
            byte = map[text[counter]];
            byte = byte << 6;
            tbyte = map[text[counter + 1]];
            byte = byte | tbyte;
            std::cout << byte;
            counter++;
            inc_l += 2;
            break;
        case 6:
            counter++;
            inc_l = 0;

        default:
            break;
        }
    }
}