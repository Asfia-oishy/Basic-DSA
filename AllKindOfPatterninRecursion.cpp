#include <bits/stdc++.h>
using namespace std;

/*
// all subsequence
void func(int ind, vector<int> &v, int len, vector<int> &ans)
{
    if (ind == len)
    {
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
        return;
    }
    ans.push_back(v[ind]);
    func(ind + 1, v, len, ans);
    ans.pop_back();
    func(ind + 1, v, len, ans);
    return;
}

int main()
{
    vector<int> v = {1, 2, 3};
    vector<int> ans;
    int n = v.size();
    func(0, v, n, ans);
}
*/

/*
// subseq with sum k
void func(int ind, int sum, vector<int> &v, int len, vector<int> &ans, int k)
{
    if (ind == len)
    {
        if (sum == k)
        {
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
            cout << endl;
        }
        return;
    }
    ans.push_back(v[ind]);
    sum += v[ind];
    func(ind + 1, sum, v, len, ans, k);
    ans.pop_back();
    sum -= v[ind];
    func(ind + 1, sum, v, len, ans, k);
    return;
}

int main()
{
    vector<int> v = {1, 2, 1};
    vector<int> ans;
    int n = v.size();
    int k = 2;
    func(0, 0, v, n, ans, k);

    return 0;
}
*/

// total ways
int func(int ind, int sum, vector<int> &v, int len, int k)
{
    if (ind == len)
    {
        if (sum == k)
        {
            return 1;
        }
        return 0;
    }

    sum += v[ind];
    int l = func(ind + 1, sum, v, len, k);
    sum -= v[ind];
    int r = func(ind + 1, sum, v, len, k);
    return l + r;
}

int main()
{
    vector<int> v = {2, 1, 4, 3};

    int n = v.size();
    int k = 4;
    cout << func(0, 0, v, n, k) << endl;
    ;

    return 0;
}