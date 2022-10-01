#include <iostream>
using namespace std;
int length;

int main(int argc, char const *argv[])
{
    cout << "Insert the length of of array: ";
    cin >> length;
    int a[length], b[length];

    cout << "Insert the first array: " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << "Enter element a" << i + 1 << " : ";
        cin >> a[i];
    }
    cout << "Insert the second array: " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << "Enter element b" << i + 1 << " : ";
        cin >> b[i];
    }

    cout << "Intersection: " << endl;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (a[i] == b[j])
            {
                cout << a[i] << endl;
            }
        }
    }
    return 0;
}