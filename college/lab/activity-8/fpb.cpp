#include <iostream>
using namespace std;

int fpb(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return fpb(b, a%b);
    }
}


int main(int argc, char const *argv[])
{   
    int a, b;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;

    cout << "The greatest common divisor of " << a << " and " << b << " is " << fpb(a, b) << endl;
    return 0;
}
