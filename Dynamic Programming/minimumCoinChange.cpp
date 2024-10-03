#include <bits/stdc++.h>
using namespace std;

//here 1st row is filled with 0

int main()
{
    vector<int> coins = {1,5,6,9}; // Coin denominations
    int w = 10;                   // Total amount of w needed

    // 2D vector to store results, initialized to 0
    vector<vector<int>> a(coins.size() + 1, vector<int>(w + 1, -1));

    for (int i = 0; i <= w; i++)
        a[0][i] = INT_MAX; //1st row


    // Iterate over the coins
    for (int i = 1; i <= coins.size(); i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (j == 0)
            {
                // There's one way to make 0 w: by not using any coins
                a[i][j] = 0;
            }

            else if (coins[i - 1] > j)
            {
                // If the coin value is greater than the current amount, exclude this coin
                    a[i][j] = a[i - 1][j];
            }
            else
            {
                a[i][j] = min(a[i - 1][j] , 1+ a[i][j - coins[i - 1]]); // Include or exclude the coin
            }
        }
    }

    // Output the number of ways to make the w
    cout << a[coins.size()][w] << endl;

    return 0;
}
