#include <iostream>
using namespace std;

float x, y, z, largest;

int main(int argc, char const *argv[])
{
    cout << "input three numbers" << endl;
    cout << "inputkan bilangan 1 : ";
    cin >> x;
    cout << "inputkan bilangan 2 : ";
    cin >> y;
    cout << "inputkan bilangan 3 : ";
    cin >> z;

    largest = x;
    if (y > largest)
        largest = y;
    if (z > largest)
        largest = z;

    cout << "bilangan terbesar adalah : " << largest << endl;
    return 0;
}
