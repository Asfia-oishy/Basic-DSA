
            {
                a[i][j] = a[i - 1][j];
            }

            else
            {
                if (i <= 0)
                    a[i][j] = a[i][j - coins[i]];
                else
                    a[i][j] = a[i - 1][j] + a[i][j - coins[i]];
            }
        }
    }

    cout << a[coins.size()-1][change] << endl;

    return 0;
}