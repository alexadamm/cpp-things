#include <iostream>
using namespace std;

int ackerman(int m, int n) {
    return (m == 0)? n+1 : (n == 0)? ackerman(m-1, 1) : ackerman(m-1, ackerman(m, n-1));
}

int main(int argc, char const *argv[])
{
    int m, n;
    cout << "Enter m: ";
    cin >> m;
    cout << "Enter n: ";
    cin >> n;

    cout << ackerman(m, n) << endl;
}
