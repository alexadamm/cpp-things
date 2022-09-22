#include <iostream>
using namespace std;

int year;
bool isLeap = false;

int main(int argc, char const *argv[])
{

    cout << "input year: ";
    cin >> year;

    if (year % 4 == 0 && year % 400 == 0 && year % 100 == 0)
    {
        isLeap = true;
    }
    else if (year % 4 == 0 && year % 100 != 0)
    {
        isLeap = true;
    }

    (isLeap) ? cout << year << " is a leap year" << endl
             : cout << year << " is not a leap year" << endl;

    return 0;
}
