#include <bits/stdc++.h>
using namespace std;

// step 1 : run dfs on whole graph multiple times if needed to store node, based on their finishing time
// step 2 : reverse the graph
// step 3 : run dfs on reversed graph(popping stored nodes)

void dfs(int src, vector<vector<int>> &g, vector<bool> &visited, stack<int> &s)
{
    visited[src] = true;

    for (int i = 0; i < g[src].size(); i++)
    {
        int v = g[src][i];
        if (!visited[v])
        {
            dfs(v, g, visited, s);
        }
    }
    s.push(src);
}

void find_scc(int src, vector<vector<int>> &g, vector<bool> &visited)
{
    visited[src] = true;
    cout << src << " ";
    for (int i = 0; i < g[src].size(); i++)
    {
        int v = g[src][i];
        if (!visited[v])
        {
            find_scc(v, g, visited);
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> g(V), rev_g(V);

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        rev_g[v].push_back(u);
    }

    vector<bool> visited(V, false);
    stack<int> s;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(0, g, visited, s);
    }

    visited.assign(V, false);
    int i = 1;
    while (!s.empty())
    {
        int src = s.top();
        s.pop();
        if (!visited[src])
        {
            cout << "scc " << i << " : ";
            find_scc(src, rev_g, visited);
            cout << endl;
            i++;
            
        }
        
    }
}