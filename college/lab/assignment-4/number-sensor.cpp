#include <iostream>
using namespace std;

int n, sensor;

int main(int argc, char const *argv[])
{
    cout << "enter 2 integers: ";
    cin >> n >> sensor;

    for (int i = 1; i <= n; i++)
    {
        (i % sensor == 0) ? cout << "*" : cout << i;
        cout << " ";
    }
    cout << endl;
    return 0;
}
