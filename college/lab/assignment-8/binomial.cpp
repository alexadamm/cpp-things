#include <iostream>
using namespace std;

int binomial(int n, int k) {
    return (k == 0 || n == k)? 1: binomial(n-1, k-1) + binomial(n-1, k);
}

int main(int argc, char const *argv[])
{
    int n, k;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;
    cout << binomial(n, k) << endl;
}
