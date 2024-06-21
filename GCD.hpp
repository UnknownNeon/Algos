/*The GCD/HCF algorithm to check coprimes;

Structure of the algo :
    Q   A   B   R  |                  x,y,z : values in integer
        x   y   z  |                  Q:Quotient
                   |                  A:The bigger valure wher A>B
                   |                  B:The Smaller Value where B<A
                   |                  R:The remaider
    -----------------

    Q   A   B   R   |
        x   y   z   |
        y   z   Cal |               Cal : Calculate the remainder
                    |
                    |
                    |
    -----------------
    Q   A   B   R                   Q:Quotient
                                    A:The bigger valure wher A>B
                                    B:The Smaller Value where B<A
                                    R:The remaider
         x   0
    -----------------
    We Stop whern B:= 0 , therefore the Value of A is our GCD

    Therefore if GCD is 1 we have them as Co-Primes ! ;


    HERE IN THIS CASE I DONT CONSIDER THE Q AS IT IS USELESS IN NORMAL EUCLDS ALGO.

*/

#include <iostream>

int GCD(int A, int B, int R = 0, int counter = 0)
{
    if(counter == 0 ){
        if(A < B ){
            int temp = B;
            B = A;
            A = temp;
        }
        R = A % B;
    }
    counter++;

    std::cout << "step: " << counter << "\t|" << A << "\t" << B << "\t" << R << std::endl;
    if (B == 0)
        return A;

    // The Logic implemented here as Refered to above
    R = A % B;
    A = B;
    B = R;

    GCD(A, B, R, counter);
}

// int main()
// {
//     int A, B, out;

//     std::cout << "Enter the first number : " << std::endl;
//     std::cin >> A;
//     std::cout << "Enter the Second number : " << std::endl;
//     std::cin >> B;

//     std::cout << "Steps\t|"
//               << "A"
//               << "\t"
//               << "B"
//               << "\t"
//               << "R" << std::endl;

//         out = GCD(A, B);
//         std::cout << std::endl;
//         std::cout << "The GCD is : " << out << std::endl
//                   << (out == 1 ? "And are Co-primes" : " ") << std::endl;
//     }
//     return 0;
// }