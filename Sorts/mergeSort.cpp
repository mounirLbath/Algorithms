using namespace std;
#include <bits/stdc++.h>

// merge sort


int tab[100000];

// sorts tab in the interval of indices [i, j[
void sort(int i, int j)
{
    if(j <= i+1)
        return;
    
    int mid = (i+j)/2;
    sort(i, mid);
    sort(mid, j);

    int k1 = i;
    int k2 = mid;
    
    vector<int> temp;

    while(k1 < mid || k2 < j)
    {
        if(k1 < mid && k2 < j)
        {
            if(tab[k1] < tab[k2])
                temp.push_back(tab[k1++]);
            else 
                temp.push_back(tab[k2++]);
        }
        else if(k1 < mid)
            temp.push_back(tab[k1++]);
        else
            temp.push_back(tab[k2++]);
    }
    
    int k = i;
    for(int x : temp)
        tab[k++] = x;
}

int main()
{
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        cin >> tab[i];

    sort(0, N);
    for(int i = 0; i < N; i++)
        printf("%d ", tab[i]);
}