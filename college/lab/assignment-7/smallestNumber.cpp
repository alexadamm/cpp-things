#include <iostream>
using namespace std;

int n, smallest;

int smallestNumber(int number[], int n) {
    int smallest = number[0];
    for (int i = 1; i < n; i++) {
        if (smallest > number[i]) smallest = number[i];
    }
    return smallest;
}

int main(int argc, char const *argv[])
{
    cout << "Input array length: " << endl;
    cin >> n;
    int number[n];
    if (n > 100 ) n = 100;
    
    for(int i = 0; i < n; i++) {
        cout << "Input array " << i << ": " << endl;
        cin >> number[i];
    }

    smallest = number[0];
    for (int i = 0; i < n; i++) {
        if (number[i] < smallest) {
            smallest = number[i];
        }
    }

    cout << "The smallest number is " << smallestNumber(number, n) << endl;
    
    return 0;
}
