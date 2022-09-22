#include <iostream>
using namespace std;

char c;

int main(int argc, char const *argv[])
{
    cin >> c;

    (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') ? cout << c << " is an alphabet" << endl
                                                   : cout << c << " is not an alphabet" << endl;
    return 0;
}
