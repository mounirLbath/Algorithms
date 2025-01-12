using namespace std;
#include <bits/stdc++.h>

const int MAX_LENGTH = 100001;
int tab[MAX_LENGTH];

void quickSort(int begin, int end)
{
    if(begin >= end)
        return;

    int pivot = tab[end-1];
    int pivotPos = begin;
    for(int i = begin; i < end; i++)
    {
        if(tab[i] <= pivot)
        {
            swap(tab[pivotPos], tab[i]);
            pivotPos++;
        }
    }
    pivotPos--;
    quickSort(begin, pivotPos);
    quickSort(pivotPos+1, end);
}

int main()
{
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++)
        cin >> tab[i];

    quickSort(0, N);

    for(int i = 0; i < N; i++)
        cout << tab[i] << ' ';
}