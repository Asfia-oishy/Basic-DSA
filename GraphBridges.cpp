#include <bits/stdc++.h>
using namespace std;

int timer = 1;
void dfs(int src, vector<vector<int>> &g, vector<int> &t, vector<int> &low, vector<bool> &visited, int parent)
{
    visited[src] = true;
    t[src] = timer;
    low[src] = timer;
    timer++;

    for (int i = 0; i < g[src].size(); i++)
    {
        int v = g[src][i];
        if (v == parent)
            continue;
        if (!visited[v])
        {
            dfs(v, g, t, low, visited, src);
        }

        low[src] = min(low[src], low[v]);
        if (low[v] > t[src])
            cout << src << " - " << v << endl;
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    if (E == 0)
    {
        cout << "No Bridges" << endl;
        return 0;
    }

    vector<vector<int>> g(V);

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> t(V, INT_MAX), low(V, INT_MAX);
    vector<bool> visited(V, false);

    // show bridges
    cout << "Bridges : \n";
    dfs(0, g, t, low, visited, -1); // assume -1 is parent of itself
    cout << endl;

    return 0;
}