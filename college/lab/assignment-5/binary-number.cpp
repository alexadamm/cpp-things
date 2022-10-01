#include <iostream>
using namespace std;

int n;

int main(int argc, char const *argv[])
{
    cout << "Insert a number: ";
    cin >> n;
    if (n >= 0 && n < 256)
    {
        int binary[8];
        for (int i = 0; i < 8; i++)
        {
            binary[i] = n % 2;
            n /= 2;
        }
        for (int i = 7; i >= 0; i--)
        {
            cout << binary[i];
        }
    }
    else
    {
        cout << "Number should be greater or equal than 0 and less than 256";
    }
    cout << endl;
}
