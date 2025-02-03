#include <bits/stdc++.h>
using namespace std;

// Djikstra algorithm in O(Vlog(V)) with min tree

vector<pair<int, int>> graph[1001]; // adjency list with pairs (edgeEnd, weight)
int finalDist[1001]; //distance to s node
int distTree[1<<11]; // binary tree where dad = min(child1, child2)
const int IND0 = 1<<10;
int INF = 10000001;

void modify(int i, int val)
{
    i += IND0-1;
    distTree[i] = val;
    i/=2;
    while(i > 0)
    {
        distTree[i] = min(distTree[2*i], distTree[2*i+1]);
        i/=2;
    }
}

int minDist()
{
    return distTree[1];
}

int getIndMin()
{
    int i = 1;
    while(i<IND0)
    {
        if(distTree[2*i] == distTree[i])
            i = 2*i;
        else
            i = 2*i+1;
    }
    return i-IND0+1;
}

int getDist(int i)
{
    return distTree[i+IND0-1];
}


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

    for(int i = 0; i < 2*IND0; ++i)
        distTree[i] = INF;

    for(int i = 1; i<=N; ++i)
        finalDist[i] = INF;
    
    modify(s,0);
    while(minDist()<INF)
    {
        int curr = getIndMin();
        int d = minDist();

        finalDist[curr] = d; // set final dist for node curr
        modify(curr, INF); // remove it from priority queue

        cout << d << " " << curr << endl;
        for(auto e : graph[curr])
        {
            if(finalDist[e.first] == INF && getDist(e.first)>d+e.second) // if this new path is better
                modify(e.first, d+e.second);
        }
    }
}