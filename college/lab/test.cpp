#include <iostream>

using namespace std;

int ff(int a, int b) {
    if (b == 0) {
        return 1;
    }
    else if (b%2 == 1) {
        return a * ff(a, b-1);
    }
    else {
        int temp = ff(a, b/2);
        return temp * temp;
    }
}

int main(){
    int a = 2021, b = 1000;

    cout << ff(3, 3);
}