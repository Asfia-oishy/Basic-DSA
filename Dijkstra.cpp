#include <bits/stdc++.h>
using namespace std;

void Dijkstra(int src, vector<vector<pair<int, int>>> &g, vector<int> &dis)
{
    dis[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({dis[src], src});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i].second;
            int cost = g[u][i].first;
            if (dis[u] + cost < dis[v])
            {
                dis[v] = dis[u] + cost;
                pq.push({dis[v], v});
            }
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> g(V);
    vector<int> dist(V, INT_MAX);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        // cout << "Enter u ,v & weight : ";
        cin >> u >> v >> w;
        g[u].push_back({w, v});
    }
    int src;
   // cout << "source :";
    cin >> src;
    Dijkstra(src, g, dist);
    for (int i = 0; i < V; i++)
    {
        cout << "shortest dis of node " << i << " is " << dist[i] << endl; // source theke distance print hobe
    }

    return 0;
}
