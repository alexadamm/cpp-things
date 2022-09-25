#include <iostream>
using namespace std;

int maxNumber, largestDigit;

int countDigits(int number)
{
    int count = 0;
    if (number == 0)
        return 1;
    while (number > 0)
    {
        number /= 10;
        count++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    cout << "Insert the maximum number to calculate the multiplication table: ";
    cin >> maxNumber;
    maxNumber++;
    int numbers[maxNumber][maxNumber];
    largestDigit = countDigits(maxNumber * maxNumber);

    for (int i = 0; i < maxNumber; i++)
    {
        for (int j = 0; j < maxNumber; j++)
        {
            numbers[i][j] = (i) * (j);
        }
    }

    for (int j = countDigits(maxNumber); j >= 0; j--)
    {
        cout << " ";
    }
    cout << "  ";

    for (int i = 0; i < maxNumber; i++)
    {
        cout << i;
        for (int j = countDigits(i); j <= largestDigit; j++)
        {
            cout << " ";
        }
    }
    cout << endl;

    for (int i = 0; i < maxNumber; i++)
    {
        cout << i;
        for (int j = countDigits(maxNumber) - countDigits(i); j >= 0; j--)
        {
            cout << " ";
        }
        cout << "- ";
        for (int j = 0; j < maxNumber; j++)
        {
            cout << numbers[i][j];
            for (int k = largestDigit - countDigits(numbers[i][j]); k >= 0; k--)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
