#include <iostream>
using namespace std;

int month, date;

int main(int argc, char const *argv[])
{
    cout << "input number of month: ";
    cin >> month;
    cout << "input number of date: ";
    cin >> date;

    switch (month)
    {
    case 3:
    case 5:
        break;

    default:
        break;
    }

    return 0;
}
