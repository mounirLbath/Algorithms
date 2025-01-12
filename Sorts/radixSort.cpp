using namespace std;
#include <bits/stdc++.h>

const int MAX_LENGTH = 100001;
const int LOG_MAX_VAL = 30;
int tab[MAX_LENGTH];

// if MAX_VAL is at most 2^(K-1) - 1 
// In O(K*NB_VAL)

void radixSort(int begin, int end, int shift)
{
    if(begin >= end || shift < 0)
        return;

    int sepPos=begin;
    for(int i = begin; i < end; i++)
    {
        if( ( tab[i] & (1<<shift) )== 0 ) // if bit is 0
        {
            swap(tab[sepPos], tab[i]);
            sepPos++;
        }
    }
    radixSort(begin, sepPos, shift-1);
    radixSort(sepPos, end, shift-1);
}


int main()
{
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++)
        cin >> tab[i];

    radixSort(0, N, LOG_MAX_VAL);

    for(int i = 0; i < N; i++)
        cout << tab[i] << ' ';
}