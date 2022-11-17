#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int size;
    cout << "\nEnter Size of Array: ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100000;
    }

    clock_t start = clock();
    sort(arr, arr + size);
    cout << "\nSorted Array: \n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    clock_t end = clock();
    cout << "\n\nTime Taken: " << (end - start) << " microseconds \n";
}
