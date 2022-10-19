#include <iostream>
#include <stdlib.h>
#define N 20
#define RANGE 10

using namespace std;

int X[N];
int MODULE[RANGE];
int largest, largestNum;

int main(int argc, char const *argv[])
{
    for (int i = 0; i < N; i++)
    {
        X[i] = rand() % RANGE;
        cout << X[i] << endl;
    }

    largest = 0;
    largestNum = 0;

    for (int i = 0; i < RANGE; i++)
    {
        MODULE[i] = 0;
        for (int j = 0; j < N; j++)
        {
            if (X[j] == i)
            {
                MODULE[i] += 1;
            }
        }

        if (MODULE[i] > largest)
        {
            largest = MODULE[i];
            largestNum = i;
        }
    }

    cout << "Modusnya adalah " << largestNum << endl;
    return 0;
}
