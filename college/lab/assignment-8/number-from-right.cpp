#include <iostream>
#include <math.h>
using namespace std;

int number_from_right(int n) {
    return (n == 0)? 0 : (n % 10) * pow(10, (int)log10(n)) + number_from_right(n/10);
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    cout << number_from_right(n) << endl;
    return 0;
}