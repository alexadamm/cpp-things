#include <iostream>
using namespace std;

int a[2][2], b[2][2], c[2][2];

int main(int argc, char const *argv[])
{
    cout << "Enter the first matrix: " << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Enter element a" << i+1 << j+1 << " : " ;
            cin >> a[i][j];
        }
    }
    
    cout << "Enter the second matrix: " << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Enter element b" << i+1 << j+1 << " : " ;
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
