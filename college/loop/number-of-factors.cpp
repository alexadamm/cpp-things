#include <iostream>
using namespace std;

int N;
int factor;

int main(int argc, char const *argv[])
{
    cout << "Masukkan suatu bilangan bulat positif N = ";
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                factor += 1;
            }
        }
        cout << factor << " ";
        factor = 0;
    }
    return 0;
}

// 1 2 3 4 5 6 7 8 9 10
// 1 2 2 3 2 4 2 4 3 4