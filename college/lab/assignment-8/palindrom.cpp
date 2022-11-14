#include <iostream>
using namespace std;

string string_from_right(string st) {
    return (st.length() == 0)? "": st.substr(st.length()-1, 1) + string_from_right(st.substr(0, st.length()-1));
}

int main(int argc, char const *argv[])
{
    string st;
    cout << "Enter the string: ";
    cin >> st;
    (string_from_right(st) == st)? cout << "Palindrome" << endl: cout << "Not Palindrome" << endl;
    return 0;
}
