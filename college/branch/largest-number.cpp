#include <iostream>
using namespace std;

float x, y, z, largest;

int main(int argc, char const *argv[])
{
    cout << "input first number: ";
    cin >> x;
    cout << "input second number: ";
    cin >> y;
    cout << "input third number: ";
    cin >> z;

    largest = x;

    if (largest < y)
        largest = y;
    if (largest < z)
        largest = z;

    cout << "the largest number from three numbers above is: " << largest << endl;
    return 0;
}
