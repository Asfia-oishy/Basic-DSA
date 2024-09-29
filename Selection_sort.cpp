#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{

    int arr[] = {1, 4, 7, 2, 3, 6, 9, 1};

    int n = sizeof(arr) / sizeof(arr[0]);
    int min_ind;

    for (int i = 0; i < n; i++)
    {
        min_ind = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_ind])
                min_ind = j;
        }

        swap(arr[i], arr[min_ind]);
    }
    cout << "sorted - " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}