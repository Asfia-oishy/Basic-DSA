#include <bits/stdc++.h>
using namespace std;


int main()
{

    int arr[] = {1, 4, 7, 2, 3, 6, 9, 1};

    int n = sizeof(arr)/sizeof(arr[0]);

    //algo

    for(int i=1; i<n;i++)
    {
        int val = arr[i];
        int hole =i;
        while(hole>0 && arr[hole-1]>val)
        {
            arr[hole] = arr[hole-1];
            hole--;
            
        }
        arr[hole] = val;
    }


    
    cout << "sorted - " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}