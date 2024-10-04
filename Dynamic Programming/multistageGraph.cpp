#include <bits/stdc++.h>
using namespace std;

int main()
{

    int V, E;
    cin >> V >> E;

    vector<vector<int>> g(V, vector<int>(V, 0));

    for (int i = 0; i < E; i++)
    {
        int u, v, w; // 1 to n
        cin >> u >> v >> w;
        u--;
        v--;
        g[u][v] = w;
    }

    vector<int> des(V, 0), cost(V, 0);
    des[V - 1] = V - 1;
    cost[V - 1] = 0;

    for (int i = V - 1; i >= 0; i--)
    {
        int mini = INT_MAX;
        for (int j = i + 1; j < V; j++)
        {
            if (g[i][j] != 0 && g[i][j] + cost[j] < mini)
            {
                mini = g[i][j] + cost[j];
                des[i] = j; // Store the next vertex on the path
            }
        }
        if (i == V - 1)
            cost[i] = 0;
        else
            cost[i] = mini;
    }
    int i = 0;
    if (cost[0] == INT_MAX)
    {
        // No valid path
        cout << "No valid path exists from node 1 to node " << V << endl;
    }
    else
    {
        cout << "Path: " << i + 1; // Output 1-indexed path
        while (i != V - 1)
        {
            i = des[i];
            cout << " -> " << i + 1; // Convert back to 1-indexed
        }
        cout << endl;
    }

    cout << "cost - " << cost[0] << endl;

    return 0;
}