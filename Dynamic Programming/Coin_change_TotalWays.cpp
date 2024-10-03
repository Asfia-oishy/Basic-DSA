#include <bits/stdc++.h>
using namespace std;

//here 1st row is filled with 0

int main()
{
    vector<int> coins = {2, 3, 5, 10}; // Coin denominations
    int change = 15;                   // Total amount of change needed

    // 2D vector to store results, initialized to 0
    vector<vector<int>> a(coins.size() + 1, vector<int>(change + 1, -1));

    for (int i = 0; i <= change; i++)
        a[0][i] = 0; //1st row

    a[0][0] = 1;

    // Iterate over the coins
    for (int i = 1; i <= coins.size(); i++)
    {
        for (int j = 0; j <= change; j++)
        {
            if (j == 0)
            {
                // There's one way to make 0 change: by not using any coins
                a[i][j] = 1;
            }

            else if (coins[i - 1] > j)
            {
                // If the coin value is greater than the current amount, exclude this coin
                    a[i][j] = a[i - 1][j];
            }
            else
            {
                a[i][j] = a[i - 1][j] + a[i][j - coins[i - 1]]; // Include or exclude the coin
            }
        }
    }

    // Output the number of ways to make the change
    cout << a[coins.size()][change] << endl;

    return 0;
}
