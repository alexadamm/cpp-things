#include <iostream>
using namespace std;

int n, tmp, i, j;
int j = 1;

int main(int argc, char const *argv[])
{
    cout << "How many integers? " << endl;
    cin >> n;
    int arr[n];
    cout << "Write the integers seperated by space: " << endl;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Sorting
    for (i = 1; i < n; i++)
    {
        for (j = n; j >= 1; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }

    // Search for smallest missing integer
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
        if (arr[i] == j)
            j++;
    }
    cout << j << endl;
    return 0;
}
