#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001]; //adjacent list (vertices from 1 to N <= 1000)
int graphMark[1001];

vector<int> result;

bool dfs(int v)
{
    if(graphMark[v] == 1) // treating
        return false; // cycle
    else if(graphMark[v] == 2) // seen
        return true;

    graphMark[v] = 1;
    for(int i : graph[v])
    {
        if(!dfs(i))
            return false;
    }
    graphMark[v] = 2;
    result.push_back(v);
    return true;
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
    }

    

    if(dfs(1))
    {
        reverse(result.begin(), result.end());
        for(int i:result)
            cout << i << " ";
    }
    else
    {
        cout << -1;
    }
}