#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> coins = {0, 2, 3, 5, 10}; // Coin denominations
    int change = 15;                      // Total amount of change needed

    // 2D vector to store results, initialized to 0
    vector<vector<int>> a(coins.size() + 1, vector<int>(change + 1, -1));

    // Iterate over the coins
    for (int i = 0; i <= coins.size(); i++)
    {
        for (int j = 0; j <= change; j++)
        {
            if (j == 0)
            {
                // There's one way to make 0 change: by not using any coins
                a[i][j] = 1;
            }
            else if (i == 0)
            {
                a[i][j] = 0;
            }
            else if (coins[i] > j)
            {
                // If the coin value is greater than the current amount, exclude this coin
                if (i > 0)
                    a[i][j] = a[i - 1][j];
            }
            else
            {
                a[i][j] = a[i - 1][j] + a[i][j - coins[i]]; // Include or exclude the coin
            }
        }
    }

    // Output the number of ways to make the change
    cout << a[coins.size() - 1][change] << endl;

    return 0;
}
