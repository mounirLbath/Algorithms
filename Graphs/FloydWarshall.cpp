#include <bits/stdc++.h>
using namespace std;

// Floyd-Warshall in O(N^3)

struct Edge{
    int start = 0;
    int end = 0;
    int weight = 0;
};

vector<Edge> edges; // vector with pairs (startPoint, endPoint)
int dist[1001][1001];

int INF = 1000*10001;

int main()
{
    int N, E;
    cin >> N >> E; // number of nodes, number of edges, start node
    int a,b,w;
    
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= N; ++j)
        {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }

    for(int i = 0; i < E; ++i)
    {
        cin >> a >> b >> w;
        dist[a][b] = w;
        dist[b][a] = w;
    }
    
    for(int s=1; s<=N; ++s)
    {
        for(int i = 1; i<=N; ++i)
        {
            for(int j = 1; j<=N; ++j)
            { 
                if(dist[i][s]+dist[s][j] < dist[i][j])
                    dist[i][j] = dist[i][s]+dist[s][j];
            }
        }
    }

    for(int i = 1; i<=N; ++i)
    {
        for(int j = 1; j<=N; ++j)
            cout << dist[i][j] << ' ';
        cout << '\n';
    }
}