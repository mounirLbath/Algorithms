#include <bits/stdc++.h>
using namespace std;

// Djikstra algorithm

vector<pair<int, int>> graph[1001]; // adjency list with pairs (edgeEnd, weight)
int dist[1001]; //distance to s node
int INF = 10000001;

int main()
{
    int N, E, s;
    cin >> N >> E >> s; // number of nodes, number of edges, start node

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

    priority_queue<pair<int,int>> pq; // stores pairs (-dist, node) of nodes to explore
    pq.push(make_pair(0, s));

    int curr, d;
    while(!pq.empty())
    {
        tie(d, curr) = pq.top();
        pq.pop();
        
        d = -d;
        cout << d << ' ' << curr << '\n';

        for(auto x : graph[curr])
        {
            if(dist[x.first] > d + x.second)
            {
                dist[x.first] = d + x.second;
                pq.push(make_pair(-dist[x.first], x.first));
            }
        }
    }
}