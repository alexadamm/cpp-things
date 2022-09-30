#include <iostream>
using namespace std;

int a[2][2], b[2][2], c[2][2];
int main(int argc, char const *argv[])
{
    cout << "Enter the first matrix(2x2): " << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> a[i][j];
        }
        cout << endl;
    }
    cout << "Enter the second matrix(2x2): " << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> b[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < 2; i++)
    {
        cout << "| ";
        for (int j = 0; j < 2; j++)
        {   
            c[i][j] = a[i][j] + b[i][j];
            cout << c[i][j] << " ";
        }
        cout << "|" <<endl;
    } 
    return 0;
}
