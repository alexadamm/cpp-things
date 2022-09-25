#include <iostream>
using namespace std;

float number;

int main(int argc, char const *argv[])
{
    cout << "Insert a number: ";
    cin >> number;

    for (int i = number; i >= 0; i--)
    {
        if (i % 2 == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
