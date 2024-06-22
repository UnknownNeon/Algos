/* 
* A program to learn the RSA Algorithm 
* Asymetric key cryptography
*/
#include <iostream>
#include <GCD.hpp> 

#define p(x) std::cout << x << std::endl;

int main(){

    int temp = 0;

    uint32_t p , q;
    p("Enter Number a which is Prime :");
    std::cin >> p;
    p("Enter a number which is Prime :");
    std::cin >> q;

    //check if p and q are actually primes 
    for(int i = 2; i <= ((p > q ) ? p : q); i ++ ){
        if(p % i  == 0 || q % i == 0){
            temp++;
        }
    }
    if(temp != 2 ){
        throw std::runtime_error("Not prime Numbers entered  ");
    }

    //Calculatin N
    uint32_t n = p*q;

    //Calculating the eulers Totient function phi(n) ;Because both are primes we can us the given formula
    uint32_t totient = (p-1)*(q-1);

    //Choose the value of e such that 1 < e < phi(n) and gcd(phi(n) , e) == 1 ; This is also out encryption key 
    int e = 2 ; 

    while(e < totient) {
        if(GCD(totient, e) == 1)
        break;
        e++;
    }

    // Calculate the value of d ; This is also our decryption key
    // d = e^-1 mod phi(n)
    // therefor, e d mod phi(n) == 1 
    int d = 1 ;

    while(true ){
        if((e * d) % totient == 1 )
        break;
        d++;
    }

    //generating the Publick Key
    std::cout << "{Public key  {e,n}: }" << e << "," << n <<std::endl;
    std::cout << "{Private key {d,n}: }" << d << "," << n <<std::endl;


    //Encryprion 
    //The formula for encryption being : c = m^e mod n where m is the length of plain text  cannot be used 

    return 0;   
}