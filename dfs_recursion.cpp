#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> g, int src, vector<bool> &visited)
{
    int u = src;
    visited[u] = true;
    cout << u << " ";
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (!visited[v])
        {
            dfs(g, v, visited);
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> g(V);

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v); // adding edges
        g[v].push_back(u);
    }

    vector<bool> visited(V, false);

    dfs(g, 0, visited);
    return 0;
}