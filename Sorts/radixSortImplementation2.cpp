using namespace std;
#include <bits/stdc++.h>
const int MAX_LENGTH = 100001;
const int LOG_MAX_VAL = 30;
int tab[MAX_LENGTH];

//first treat the small bits

int main()
{
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++)
        cin >> tab[i];

    queue<int> bigVal;
    queue<int> smallVal;
    for(int i = 0; i <= LOG_MAX_VAL; i++)
    {
        for(int j= 0; j < N; j++)
        {
            if( ((tab[j]>>i)&1))
                bigVal.push(tab[j]);
            else
                smallVal.push(tab[j]);
        }
        for(int j= 0; j < N; j++)
        {
            if(!smallVal.empty())
            {
                tab[j] = smallVal.front();
                smallVal.pop();
            }
            else
            {
                tab[j] = bigVal.front();
                bigVal.pop();
            }
        }
    }
    for(int i = 0; i < N; i++)
        cout << tab[i] << ' ';
}