#include <iostream>
using namespace std;

float *insertion(float arr[], int size, bool isAsc)
{
    float temp;
    for (int i = 1; i < size; i++)
    {
        temp = arr[i];
        int j = i - 1;
        while (j >= 0 && ((isAsc) ? (arr[j] > temp) : (arr[j] < temp)))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    return arr;
}

float *selection(float arr[], int size, bool isAsc)
{
    float temp;
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if ((isAsc) ? arr[j] < arr[min] : arr[j] > arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    return arr;
}

int main(int argc, char const *argv[])
{
    int size;
    clock_t start, end;
    cout << "Enter the size of the array: ";
    cin >> size;
    float x[size];
    for (int i = 0; i < size; i++)
    {
        x[i] = rand() % 100000;
    }

    start = clock();
    float *insertionAsc = insertion(x, size, true);
    cout << endl;
    end = clock();
    cout << "Time taken by insertion sort in ascending order: " << end - start << " microseconds \n"
         << endl;

    start = clock();
    float *insertionDesc = insertion(x, size, false);
    cout << endl;
    end = clock();
    cout << "Time taken by insertion sort in descending order: " << end - start << " microseconds \n"
         << endl;

    start = clock();
    float *selectionAsc = selection(x, size, true);
    cout << endl;
    end = clock();
    cout << "Time taken by selection sort in ascending order: " << end - start << " microseconds \n"
         << endl;

    start = clock();
    float *selectionDesc = selection(x, size, false);
    end = clock();
    cout << "\nTime taken by selection sort in descending order: " << end - start << " microseconds \n";
}
