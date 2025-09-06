#include <bits/stdc++.h>
using namespace std;

// A SWERC training problem Heatwave https://www.spoj.com/MODAL25/problems/XT02A/
// Implements Kruskal and Tarjan algorithms

int N, M, K;
struct Edge
{
    int start;
    int end;
    int d;
    Edge(int a, int b, int d2)
    {
        start = a;
        end = b;
        d = d2;
    }
};
vector<Edge> edge;
vector<Edge> edgeFinal;
vector<int> parent = {0};
vector<int> ccEdge = {0};
vector<vector<pair<int, int>>> questions(30005); // questions[i] contains list of pairs(time, j) where i,j query and time is the order for which it was asked
vector<pair<int, int>> answers;                  // answers in the format (time_question, answer)
vector<vector<int>> tree(30005);                 // for 1 <= i <= N, vertices, for N+1 <= i <= 2N-1, edges (edge edgeFinal[i-1-N])
vector<bool> visited(30005);

bool compare(Edge &a, Edge &b)
{
    return a.d >= b.d;
}

int find(int i)
{
    if (parent[i] != i)
    {
        parent[i] = find(parent[i]);
    }

    return parent[i];
}

void unionOp(int i, int j)
{
    parent[find(j)] = find(i);
}

void tarjan(int currentNode)
{
    if (visited[currentNode])
        return;
    visited[currentNode] = true;
    if (currentNode <= N)
    {
        for (auto [time, otherNode] : questions[currentNode])
        {
            if (visited[otherNode]) // seen before
            {
                answers.push_back(make_pair(time, find(otherNode)));
            }
        }
    }

    for (int child : tree[currentNode])
    {
        tarjan(child);
        unionOp(currentNode, child);
    }
}

int main()
{

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++)
    {
        int X, Y, D;
        cin >> X >> Y >> D;
        edge.push_back(Edge(X, Y, D));
    }

    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;

        questions[y].push_back(make_pair(i, x));
        questions[x].push_back(make_pair(i, y));
    }

    for (int i = 1; i <= N; i++)
    {
        parent.push_back(i);
        ccEdge.push_back(i);
    }

    sort(edge.begin(), edge.end(), compare);
    int nbComp = N;
    while (!edge.empty())
    {
        while (!edge.empty() && find(edge.back().start) == find(edge.back().end))
        {
            edge.pop_back();
        }

        if (!edge.empty())
        {
            tree[N + edgeFinal.size() + 1].push_back(ccEdge[find(edge.back().start)]);
            tree[N + edgeFinal.size() + 1].push_back(ccEdge[find(edge.back().end)]);

            unionOp(edge.back().start, edge.back().end);

            edgeFinal.push_back(edge.back());
            ccEdge[find(edge.back().start)] = N + edgeFinal.size();

            edge.pop_back();
            nbComp--;
        }
    }

    // reset parent for Tarjan algorithm
    parent = {0};
    // Tarjan algorithm
    for (int i = 1; i <= 2 * N - 1; i++)
    {
        parent.push_back(i);
    }

    for (int i = edgeFinal.size() - 1; i >= 0; i--)
    {
        tarjan(i + N + 1);
    }
    sort(answers.begin(), answers.end());
    for (auto [t, a] : answers)
    {
        if (edgeFinal.size() - 1 >= a - N - 1 && a >= N + 1)
            cout << edgeFinal[a - N - 1].d << '\n';
    }
}