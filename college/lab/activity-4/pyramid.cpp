#include <iostream>
using namespace std;

int n;

int main(int argc, char const *argv[])
{
    cout << "enter number rows: ";
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
