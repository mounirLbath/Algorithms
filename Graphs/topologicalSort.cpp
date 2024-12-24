#include <bits/stdc++.h>
using namespace std;

// using Kahn's algorithm

vector<int> lab[1001];
int dEntrant[1001];
vector<int> result;
void searchFrom(int v)
{
    result.push_back(v);
    dEntrant[v] = -1; // vu
    for(int i : lab[v])
    {
        dEntrant[i]--;
    }
    for(int i : lab[v])
    {
        if(dEntrant[i] == 0)
        {
            searchFrom(i);
        }
    }
}

int main()
{
    int N, A;
    cin >> N >> A;
    for(int i = 0; i < A; ++i)
    {
        int a, b;
        cin >> a >> b;
        lab[a].push_back(b);
        dEntrant[b]++;
    }
    for(int i = 1; i <= N; ++i)
    {
        if(dEntrant[i] == 0)
        {
            searchFrom(i);
        }
    }
    if(result.size() == N)
    {
        for(int i : result)
            cout << i << " ";
    }
    else
    {
        cout << -1; // no topological sort
    }
}