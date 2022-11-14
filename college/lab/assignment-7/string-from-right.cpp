#include <iostream>
using namespace std;

string string_from_right(string st, int n) {
    if (n == 0) {
        return "";
    }
    else {
        return st.substr(st.length()-n, 1) + string_from_right(st, n-1);
    }
}

int main(int argc, char const *argv[])
{
    string st;
    int n;
    cout << "Enter the string: ";
    cin >> st;
    cout << "Enter n: ";
    cin >> n;


    cout << string_from_right(st, n) << endl;

    return 0;
}
