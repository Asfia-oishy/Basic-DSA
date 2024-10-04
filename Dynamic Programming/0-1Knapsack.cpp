#include <bits/stdc++.h>
using namespace std;

int main()
{

    int w = 8, n = 4;
    vector<int> weights = {3, 4, 6, 5};
    vector<int> profits = {2, 3, 1, 4};

    vector<pair<int, int>> wp(n);

    for (int i = 0; i < n; i++)
    {
        wp[i] = make_pair(weights[i], profits[i]);
    }

    sort(wp.begin(), wp.end()); // sorted by weights

    vector<vector<int>> a(n + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (weights[i - 1] > j)
                a[i][j] = a[i - 1][j];

            else
            {
                a[i][j] = max(a[i - 1][j], profits[i - 1] + a[i - 1][j - weights[i - 1]]);
            }
        }
    }

    cout << "ans : " << a[n][w] << endl;

    return 0;
}