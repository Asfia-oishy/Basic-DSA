#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> g, int src, vector<int> &visited)
{
    int u = src;
    visited[u] = 1;


    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (visited[v]==0)
        {
            if(dfs(g, v, visited))
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
            if (dfs(g, 0, visited))
                cycle = true;
        }
    }

    if (cycle)
        cout << "Cycle is present" << endl;
    else
        cout << "There is no cycle in the graph" << endl;
    return 0;
}