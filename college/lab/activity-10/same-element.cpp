#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int count = 0;
    int n, x;
    cout << "Enter the number of elements: ";
    cin >> n;
    int L[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> L[i];
    }
    cout << "Enter the element to search: ";
    cin >> x;

    for (int i = 0; i < n; i++)
    {
        if (L[i] == x)
            count++;
    }

    cout << "The element " << x << " is present " << count << " times." << endl;
}
