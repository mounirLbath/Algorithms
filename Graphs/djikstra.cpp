#include <bits/stdc++.h>
using namespace std;

// Djikstra algorithm without priority queue in O(V^2)

vector<pair<int, int>> graph[1001]; // adjency list with pairs (edgeEnd, weight)
const int NO_NODE = -1;
int seen[1001];
int dist[1001]; //distance to s node
int INF = 10000001;
// number of nodes, number of edges, start node
int N;
int E;
int s;

int findNext()
{
    int res = NO_NODE;
    int minDist = INF;
    for(int i = 1; i <= N; ++i)
    {
        if(!seen[i] && dist[i] < minDist)
        {
            minDist = dist[i];
            res = i;
        }
    }
    return res;
}

int main()
{
    
    cin >> N >> E >> s; 
    int a,b,w;
    for(int i = 0; i < E; ++i)
    {
        cin >> a >> b >> w;
        graph[a].push_back(make_pair(b, w));
        graph[b].push_back(make_pair(a, w));
    }

    for(int i = 1; i <= N; ++i)
    {
        dist[i] = INF;
    }
    dist[s] = 0;

    int curr, d;
    while(true)
    {
        curr = findNext();

        if(curr == NO_NODE)
            break;

        d = dist[curr];
        seen[curr] = true;

        cout << d << ' ' << curr << '\n';

        for(auto x : graph[curr])
        {
            dist[x.first] = min(dist[x.first],d + x.second);
        }
    }
}