#include <iostream>
using namespace std;

int first, last;
bool isPrime(int n) {
    for (int i = 2; i < n; i++) {
        if (n%i == 0) return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    cout << "Enter two numbers separated by space: ";
    cin >> first >> last;
    int primes[last-first];

    for (int n = first; n <= last; n++) {
        if (isPrime(n)) {
            cout << n << endl;
        }
    }
    return 0;
}
