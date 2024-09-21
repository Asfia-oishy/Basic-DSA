#include <bits/stdc++.h>
using namespace std;
int timer = 1;
void dfs(int src, vector<vector<int>> &g, vector<int> &t, vector<int> &low, vector<bool> &visited, int parent, vector<int> &ap)
{
    visited[src] = true;
    t[src] = timer;
    low[src] = timer;
    timer++;
    int child = 0;

    for (int i = 0; i < g[src].size(); i++)
    {
        int v = g[src][i];
        if (v == parent)
            continue;
        if (!visited[v])
        {
            dfs(v, g, t, low, visited, src,ap);
            child++;
        }

        low[src] = min(low[src], low[v]);
        if (low[v] >= t[src] && parent != -1)
            ap[src] = 1;
    }
    if (parent == -1 && child > 1)
        ap[src] = 1;
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
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> t(V, INT_MAX), low(V, INT_MAX);
    vector<bool> visited(V, false);
    vector<int> ap(V, 0);

    dfs(0, g, t, low, visited, -1, ap); // assume -1 is parent of itself
    bool flag = false;

    cout << "Articulation Points : \n";
    for (int i = 0; i < V; i++)
    {
        if (ap[i] == 1)
        {
            cout << i << endl;
            flag = true;
        }
    }

    if (!flag)
        cout << "No Articulation Points" << endl;

    return 0;
}