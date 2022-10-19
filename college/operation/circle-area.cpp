#include <iostream>
#include <math.h>
#define PI 3.14
using namespace std;

float result, r;

int main(int argc, char const *argv[])
{
    cout << "input radius of circle: ";
    cin >> r;

    result = PI * pow(r, 2);
    cout << "the area of cirle is " << result << endl;
    return 0;
}
