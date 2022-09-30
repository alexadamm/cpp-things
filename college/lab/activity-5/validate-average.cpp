#include <iostream>
using namespace std;

float num[10], sum, average, numTotal;
char isBreak;

bool stop() {
    cout << "Do you want to insert another number? (y/N): ";
    cin >> isBreak;
    return (isBreak == 'y')? 0: 1;
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter number " << i + 1 << ": ";
        cin >> num[i];
        sum += num[i];
        numTotal = i+1;
        if (stop()) break;
    }

    cout << "The average is " << sum / numTotal << endl; 
    return 0;
}
