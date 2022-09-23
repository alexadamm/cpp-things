#include <iostream>
using namespace std;

int n, k;
bool isPrime = true;

int main(int argc, char const *argv[])
{
    cout << "Enter a number: ";
    cin >> n;

    for (k = 2; k < n; k++)
    {
        if (n % k == 0)
        {
            isPrime = false;
        }
    }

    cout << n << ((isPrime) ? " is a prime number" : " is not a prime number") << endl;
    return 0;
}
