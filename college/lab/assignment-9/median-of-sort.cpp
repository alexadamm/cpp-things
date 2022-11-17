#include <iostream>
using namespace std;

float medianOfSorted(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return (size % 2 == 0) ? (arr[size / 2] + arr[size / 2 - 1]) / 2.0 : arr[size / 2];
}

int main(int argc, char const *argv[])
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int x[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cout << "x[" << i << "] = ";
        cin >> x[i];
    }
    cout << "The median of the array is: " << medianOfSorted(x, size) << endl;
}
