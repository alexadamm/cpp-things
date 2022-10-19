#include <iostream>
#include <math.h>
using namespace std;

double num;
int digit;

int main()
{
	cout << "input number: ";
	cin >> num;
	digit = 0;
	while (num >= 1)
	{
		num /= 10;
		digit++;
	}
	cout << digit;
	int arr[digit];

	for (int i = 0; i < digit; i++)
	{
		arr[i] = 0;
	}

	for (int i = 1; i <= digit; i++)
	{
		int divider = pow(10, i);
		for (int j = num; j % divider != 0; j--)
		{
			arr[i - 1]++;
			num--;
		}
	}

	for (int i = 0; i < digit; i++)
	{
		cout << arr[digit];
	}
}
