#include <iostream>
#include <math.h>
using namespace std;

float x, y, r;

int main(int argc, char const *argv[])
{
    cout << "input x and y of triangle to find r" << endl;
    cout << "input x: ";
    cin >> x;
    cout << "input y: ";
    cin >> y;

    r = sqrt(pow(x, 2) + pow(y, 2));
    cout << "r = " << r << endl;
    return 0;
}
