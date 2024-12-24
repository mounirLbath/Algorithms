#include <bits/stdc++.h>
using namespace std;

// using Kahn's algorithm

vector<int> graph[1001];
int dIn[1001];
vector<int> result;
void searchFrom(int v)
{
    result.push_back(v);
    dIn[v] = -1; // vu
    for(int i : graph[v])
    {
        dIn[i]--;
    }
    for(int i : graph[v])
    {
        if(dIn[i] == 0)
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
        graph[a].push_back(b);
        dIn[b]++;
    }
    for(int i = 1; i <= N; ++i)
    {
        if(dIn[i] == 0)
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