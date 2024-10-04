#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w = 15, n = 7;
    vector<int> profits = {5, 10, 15, 7, 8, 9, 4};
    vector<int> weights = {1, 3, 5, 4, 1, 3, 2};
    vector<int> pw(n); // p/w

    priority_queue<pair<int, pair<int, int>>> pq; // p/w,p,w

    for (int i = 0; i < n; i++)
    {
        pw[i] = profits[i] / weights[i];
        pq.push(make_pair(pw[i], make_pair(profits[i], weights[i])));
    }

    int total = 0;
    while (w > 0)
    {
        int p_w = pq.top().first;
        int wi = pq.top().second.second;
        int pi = pq.top().second.first;
        pq.pop();

        if (w > wi)
        {
            total += pi;
        }
        else
        {
            total += (w*p_w);
        }
        w -= wi;
    }
    cout << total << endl;

    return 0;
}