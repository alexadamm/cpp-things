#include <iostream>
#include <math.h>
using namespace std;

float a, b, c, s, result;

int main(int argc, char const *argv[])
{
    cout << "input first, second, and third side of triangle" << endl;
    cout << "input first side: ";
    cin >> a;
    cout << "input second side: ";
    cin >> b;
    cout << "input third side: ";
    cin >> c;

    s = (a + b + c) / 2;

    result = sqrt((s) * (s - a) * (s - b) * (s - c));
    cout << "the area of triangle is " << result << endl;
    return 0;
}
