#include <bits/stdc++.h>
using namespace std;

bool BellmanFord(int src, int V, int E, vector<pair<int, pair<int, int>>> &g, vector<int>& d)
{
    d[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = g[j].second.first;
            int v = g[j].second.second;
            int w = g[j].first;
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
            }
        }
    }

    for (int i = 0; i < E; i++)
    {
        int u = g[i].second.first;
        int v = g[i].second.second;
        int w = g[i].first;
        if (d[u] + w < d[v])
        {
            d[v] = d[u] + w;
            return true;
        }
    }
    return false;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<pair<int, pair<int, int>>> g(E); // vector of edges and cost
    vector<int> dist(V, INT_MAX);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        // cout << "Enter u ,v & weight : ";
        cin >> u >> v >> w;
        g[i]={w, {u, v}};
    }
    int src;
    // cout << "source :";
    cin >> src;
    if (BellmanFord(src, V, E, g, dist))
    {
        cout << "negative cycle found" << endl;
    }
    else
    {
        for (int i = 0; i < V; i++)
        {
            cout << "shortest dis of node " << i << " is " << dist[i] << endl; // source theke distance print hobe
        }
    }
    return 0;
}