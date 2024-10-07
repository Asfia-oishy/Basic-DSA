#include <bits/stdc++.h>
using namespace std;


//type 1
/*
void findCombSum(int ind, vector<int> &v, vector<int> &ans, int target, int len)
{
    if (ind == len)
    {
        if (target == 0)
        {
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
            cout << endl;
        }
        return;
    }
    if (v[ind] <= target)
    {
        ans.push_back(v[ind]);
        findCombSum(ind, v, ans, target - v[ind], len);
        ans.pop_back();
    }
    findCombSum(ind + 1, v, ans, target, len);
}

int main()
{

    vector<int> v = {2, 3, 6, 7};

    vector<int> ans;
    int target = 7;
    int n = v.size();

    findCombSum(0, v, ans, target, n);

    return 0;
}
*/

//type 2
void findCombSum(int ind, vector<int> &v, vector<int> &ans, int target, int len,map<vector<int>,int> &mp)
{
    if (ind == len)
    {
        if (target == 0)
        {
            sort(ans.begin(),ans.end());
            if(mp.find(ans)==mp.end())
            {
                mp[ans]++;
                for(int i=0;i<ans.size();i++)
                {
                    cout<<ans[i]<<" ";
                }
                cout<<endl;
                
            }
        }
        return;
    }
    if (v[ind] <= target)
    {
        ans.push_back(v[ind]);
        findCombSum(ind+1, v, ans, target - v[ind], len,mp);
        ans.pop_back();
    }
    findCombSum(ind + 1, v, ans, target, len,mp);
}

int main()
{

    vector<int> v ={1,1,1,2,2};

    vector<int> ans;
    int target = 4;
    int n = v.size();
    map<vector<int>,int> mp;

    findCombSum(0, v, ans, target, n,mp);

    return 0;
}