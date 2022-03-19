#include <iostream>
using namespace std;

/*
Iterative version of fast exponentiation in O(log(N))
*/

int main()
{
    int a;
    int n;
    cin >> a >> n;

    int temp = a;
    unsigned long long int result = 1;
    while(n != 0)
    {
        if(n&1) // if the current bit is on, multiply the result by a^2^k whith k the number of iterations
            result *= temp;
        temp = temp*temp;
        n = n>>1;   // right shift n by 1 to process the other bits
    }
    cout << result;
}