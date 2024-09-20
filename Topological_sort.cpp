#include <bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int>> g, int src, vector<int> &visited)
{
    int u = src;
    visited[u] = 1;
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (visited[v]==0)
        {
            if(isCycle(g, v, visited))
            return true;
        }
         if (visited[v]==1)
        {
            return true;
        }
    }
    visited[src]=2;
    return false;
}

void top_sort(vector<vector<int>> g, int src, vector<int> &visited)
{
    int u = src;
    visited[u] = 1;
    cout << u << " ";

    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];

        if (!visited[v])
        {

            top_sort(g, v, visited);
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
    }

    vector<int> visited(V, 0);
    bool cycle = false;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (isCycle(g, 0, visited))
                cycle = true;
        }
    }

    if (cycle)
        cout << "Cycle is present. Topological Sort is impossible" << endl;

    else
    {
        visited.clear();
        visited.assign(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                top_sort(g, i, visited);
            }
        }
    }

    return 0;
}