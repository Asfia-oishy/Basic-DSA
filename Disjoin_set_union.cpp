#include <bits/stdc++.h>
using namespace std;

void make_parent(int d, vector<int> &par)
{
    par[d] = d;
}

int find_p(int d, vector<int> par)
{
    if (par[d] == d)
        return d;
    else

        return par[d] = find_p(par[d], par);
}
void unite(int a, int b, vector<int> &par)
{
    int root_a = find_p(a, par);
    int root_b = find_p(b, par);
    if (root_a == root_b)
        return;
    else
        par[root_b] = root_a;
}
int main()
{
    vector<int> nodes = {0, 1, 2, 3, 4, 5}; // distinct nodes. not connected
    int len = nodes.size();
    vector<int> parent(len);

    for (int i = 0; i < len; i++)
    {
        make_parent(nodes[i], parent);
    }

    // unite
    for (int i = 0; i < len - 1; i++)
    {
        unite(nodes[i], nodes[i + 1], parent);
    }

    for (int i = 0; i < len; i++)
    {
        cout << find_p(nodes[i], parent) << " "; // parent of all nodes are same means they are connected in one component
    }

    return 0;
}