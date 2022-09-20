#include <iostream>
#include <math.h>
using namespace std;

float a, b, c, d, x1, x2, x;

int main(int argc, char const *argv[])
{
    cout << "input a, b, c of quadratic equation on ax^2 + bx + c" << endl;
    cout << "input a: ";
    cin >> a;
    cout << "input b: ";
    cin >> b;
    cout << "input c: ";
    cin >> c;

    d = pow(b, 2) - (4 * a * c);

    if (d > 0)
    {
        x1 = (-(b) + sqrt(d)) / (2 * a);
        x2 = (-(b)-sqrt(d)) / (2 * a);

        cout << "roots of the quadratic equation above are" << endl;
        cout << "x1 = " << x1 << " and x2 = " << x2 << endl;
    }
    else if (d == 0)
    {
        x = (-(b) + sqrt(d)) / (2 * a);

        cout << "root of the quadratic equation above is" << endl;
        cout << "x1 = " << x1 << endl;
    }
    else
    {
        cout << "root of the equation is imaginary" << endl;
    }

    return 0;
}
