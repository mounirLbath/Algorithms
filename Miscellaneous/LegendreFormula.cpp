#include <bits/stdc++.h>
using namespace std;



int main()
{
    int N, p;
    cin >> N >> p;

    int powerP = p;
    int res = 0;
    while(powerP <= N)
    {
        res += N/powerP;
        powerP *= p;
    }
    cout << res;
    
}