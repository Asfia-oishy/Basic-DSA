#include <bits/stdc++.h>
using namespace std;

void SumofSubset(int ind, int sum, vector<int> &v, int len, vector<int> &ans)
{
    if (ind == len)
    {
        ans.push_back(sum);
        return;
    }

    sum += v[ind];
    SumofSubset(ind + 1, sum, v, len, ans);

    sum -= v[ind];
    SumofSubset(ind + 1, sum, v, len, ans);
    return;
}

int main()
{
    vector<int> v = { 2, 3};
    vector<int> ans;
    int n = v.size();
    SumofSubset(0, 0, v, n, ans);
    sort(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}