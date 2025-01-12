using namespace std;
#include <bits/stdc++.h>

const int MAX_VAL = 100000;
int tab[2*MAX_VAL+1];

int main()
{
    int N;
    cin >> N;
    
    int x;
    for(int i = 0; i < N; i++)
    {
        cin >> x;
        tab[x+MAX_VAL]++;
    }

    for(int i = -MAX_VAL; i <= MAX_VAL; i++)
    {
        if(tab[i+MAX_VAL])
        {
            for(int j = 0; j < tab[i+MAX_VAL]; j++)
                cout << i << ' ';
        }
    }
}