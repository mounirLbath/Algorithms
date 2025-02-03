#include <bits/stdc++.h>
using namespace std;

// Bellman-Ford to find shortest path in O(mn)

struct Edge{
    int start = 0;
    int end = 0;
    int weight = 0;
};

vector<Edge> edges; // vector with pairs (startPoint, endPoint)
int dist[1001];

int INF = 1000*10001;

int main()
{
    int N, E;
    cin >> N >> E; // number of nodes, number of edges, start node
    int a,b,w;
    for(int i = 0; i < E; ++i)
    {
        cin >> a >> b >> w;
        edges.push_back({a, b, w});
    }
    
    for(int i = 2; i <= N; ++i)
        dist[i] = INF;
    
    dist[1] = 0;
    bool decrease;
    for(int i = 0; i <= N; ++i)
    {
        decrease = false;
        for(Edge& e : edges)
        {
            if(dist[e.end] > dist[e.start] + e.weight)
            {
                decrease = true;
                dist[e.end] = dist[e.start] + e.weight;
            }
        }
    }

    if(decrease)
        cout << "Negative cycle";
    else
        cout << dist[N];
}