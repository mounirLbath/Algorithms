#include <bits/stdc++.h>
using namespace std;

// solves problem https://www.france-ioi.org/algo/task.php?idChapter=537&iOrder=5
// going down 
// binary tree to perform efficiently 2 tasks on a vector of length N:
// shift values in the interval [L,R] by s in O(log(N)^2); read the value at index K in O(log(N))
// 

const int length = 1<<17;
int tab[2*length];

int val(int k)
{
    k += length;
    int res = 0;
    while(k > 0)
    {
        res += tab[k];
        k /= 2;
    }
    return res;
}


// currD exclu, d exclu
void decal(int curr,int currG, int currD, int g, int d, int shift)
{
    if(g == currG && d == currD)
    {
        tab[curr] += shift;
        return;
    }

    int mid = (currG+currD)/2;
    if(d <= mid)
        decal(2*curr, currG, mid, g, d, shift);
    else if(mid <= g)
        decal(2*curr+1, mid, currD, g, d, shift);
    else
    {
        decal(2*curr, currG, mid, g, mid, shift);
        decal(2*curr+1, mid, currD, mid, d, shift);
    }
}

int main()
{
    int H, R;
    cin >> H >> R;
    char c;
    int k, g, d, s;

    for(int i = 0; i < R; i++)
    {
        cin >> c;
        if(c=='V')
        {
            cin >> k;
            cout << val(k) << '\n';
        }
        else
        {
            cin >> g >> d >> s;
            d++;
            decal(1, 0, length, g, d, s);
        }
    }

}