#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int rows;
    cout << "input number of rows: ";
    cin >> rows;
    for (int i = rows; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "   ";
        }
        for (int k = 1; k <= 2 * (rows - i) + 1; k += 1)
        {
            cout << " * ";
        }
        cout << endl;
    }
    return 0;
}
