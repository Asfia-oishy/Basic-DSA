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