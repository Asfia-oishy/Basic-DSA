#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &L, vector<int> &R, vector<int> &arr)
{
    int nL = L.size();
    int nR = R.size();
    int i = 0, j = 0, k = 0;
    while (i < nL && j < nR)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < nL)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < nR)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int n)
{
    if (n < 2)
        return;

    int mid = n / 2;
    vector<int> L(mid);
    vector<int> R(n - mid);
    for (int i = 0; i < mid; i++)
        L[i] = arr[i];
    for (int i = mid; i < n; i++)
        R[i - mid] = arr[i];

    mergeSort(L, L.size());
    mergeSort(R, R.size());
    merge(L, R, arr);
}

int main()
{

    vector<int> arr = {1, 4, 7, 2, 3, 6, 9, 1, 3, 8};

    int n = arr.size();

    mergeSort(arr, n);

    cout << "sorted - " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}