#include <iostream>
using namespace std;

string stringRepeat(string str, int n) {
    string result = "";
    for (int i = 0; i < n; i++) {
        result += str;
    }

    return result;
}

int main(int argc, char const *argv[])
{
    string str;
    int n;
    cout << "Masukkan string: ";
    cin >> str;
    cout << "Sisipkan n: ";
    cin >> n;

    cout << stringRepeat(str, n) << endl;

    return 0;
}
