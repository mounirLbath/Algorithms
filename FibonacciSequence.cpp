#include <iostream>
using namespace std;

/* Fibonacci Sequence in O(log(N)) using fast exponentiation
 * Author: Mounir LBATH
 * Note that for N>=94, it exceeds the unsigned long long int limit
 **/

// Define a basic 2*2 matrix structure
struct Matrix
{
    /*(a b)
      (c d)*/
    unsigned long long int a{},b{},c{},d{};

    // Matrix multiplication
    Matrix operator*(const Matrix& m)
    {
        Matrix result;
        result.a= a*m.a+b*m.c;
        result.b= a*m.b+b*m.d;
        result.c= c*m.a+d*m.c;
        result.d= c*m.b+d*m.d;
        return result;
    }
};

int main()
{
    Matrix fibonacci{0,1,1,1};
    int n;
    cout << "n? ";
    cin >> n;
    
    // Compute fibonacci^n in O(log(N)) using fast exponentiation (thanks to product associativity on square matrices)
    Matrix temp = fibonacci;
    Matrix result{1,0,0,1}; //identity matrix

    while(n != 0)
    {
        if(n&1) // if the current bit is on, multiply the result by fibonacci^2^k whith k the number of iterations
            result = result*temp;

        temp = temp*temp;
        n = n>>1;   // right shift n by 1 to process the other bits
    }
    /* Using the well known fact that
    (0 1)^n   (F_{n-1}   F_n  )
    (1 1)   = (  F_n   F_{n+1})
    */
    cout << "F_n = "<<result.b;
}