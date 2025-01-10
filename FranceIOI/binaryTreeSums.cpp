using namespace std;
#include <bits/stdc++.h>

// solves https://www.france-ioi.org/algo/task.php?idChapter=537&iOrder=2
// second implementation of such binary trees (going up)
// binary tree to perform on vector of length N:
// modify a value at a certain index in O(log(N)), give the sum of values between [L,R] in O(log(N))

const int MAX_LENGTH = 256*1024;
int items[MAX_LENGTH];
const int p = MAX_LENGTH/2;
int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> items[i+p];
    for(int i = p-1; i > 0; i--)
        items[i] = items[2*i]+items[2*i+1];
    int R;
    cin >> R;
    char c;
    int a, b;
    for(int i = 0; i < R; i++)
    {
        cin >> c >> a >> b;
        if(c == 'M')
        {
            int j = p+a;
            items[j] = b;
            j/=2;
            while(j > 0)
            {
                items[j] = items[2*j]+items[2*j+1];
                j /= 2;
            }
        }
        else
        {
            int g = a+p;
            int d = b+p;
            int res;
            if(g < d)
                res = items[g]+items[d];
            else
                res = items[g];
            while(g/2 < d/2)
            {
                if(g%2 == 0)
                    res += items[g+1];
                if(d%2==1)
                    res += items[d-1];
                g /= 2;
                d /= 2;
            }
            cout << res << '\n';
        }
    }
}