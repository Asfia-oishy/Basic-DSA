#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef pair<int, int> p_int;
typedef pair<int, pair<int, int>> pp_int; //(cost,(v1,v2))
vector<p_int> graph[1000000000];
int V, E;
priority_queue<pp_int, vector<pp_int>, greater<pp_int>> pq; // min value is on top

void prims(int src)
{

    int n1, n2, cost, edge_count = 0;
    bool visited[V];
    for (int j = 0; j < V; j++)
        visited[j] = false;
    //  cout << "hi";
    n1 = src;
    visited[src] = true;
    int limit = E*2;
    while (limit--)
    {

        for (int i = 0; i < graph[n1].size(); i++)
        {
            n2 = graph[n1][i].second;
            cost = graph[n1][i].first;
            if (visited[n2] == false)
                pq.push(make_pair(cost, make_pair(n1, n2)));
        }

        n1 = pq.top().second.first;
        n2 = pq.top().second.second;
        cost = pq.top().first;
        
        if (visited[n1] && !visited[n2])
        {
            cout << n1 << " - " << n2 << " cost = " << cost << endl;
            visited[n2] = true;
            edge_count++;
        }

        if (edge_count == V - 1)
            break;
        n1 = n2;
        pq.pop();
    }
}

void addEdge(int v1, int cost, int v2)
{
    graph[v1].pb(make_pair(cost, v2));
    graph[v2].pb(make_pair(cost, v1));
}

int main()
{
    int cost, v1, v2;

    cout << "Enter the number of vertices and edges : ";
    cin >> V >> E;
    cout << "\nEnter Edges : (v1, cost, v2)" << endl;
    for (int i = 0; i < E; i++)
    {
        cin >> v1 >> cost >> v2;
        addEdge(v1, cost, v2);
    }

    prims(0);

    return 0;
}