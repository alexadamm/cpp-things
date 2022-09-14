#include <iostream>
#include <math.h>
using namespace std;

float n;

int main(int argc, char const *argv[])
{
    cout << "input a number: ";
    cin >> n;
    cout << "biggest integer number that is less than or equal to "
         << n << " is " << floor(n) << endl;
    return 0;
}
