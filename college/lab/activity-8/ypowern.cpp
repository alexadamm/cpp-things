#include <iostream>
using namespace std;

int fun(int y, int n) {
    if (n == 1) {
        return y;
    }
    else {
        return y * fun(y, n-1);
    }
}

int main(int argc, char const *argv[])
{
    int y, n;
    cout << "Enter the value of y: ";
    cin >> y;
    cout << "Enter the value of n: ";
    cin >> n;
    
    cout << fun(y, n) << endl;
    
    return 0;
}
