#include <iostream>
using namespace std;

int n;
int sum = 0;
bool isNegative = true;

int main(int argc, char const *argv[])
{
    while (isNegative) {
        cout << "Masukkan angka: ";
        cin >> n;
        (n <= 0)? sum += n : isNegative = false;
    }
    cout << sum << endl;
    return 0;
}
