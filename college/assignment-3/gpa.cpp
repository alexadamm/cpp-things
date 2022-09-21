#include <iostream>
#include <iomanip>
using namespace std;

float ipk, sum, score[5], ip[5];
char scoreLetter[5];
float semesterTotal = 5;

int main(int argc, char const *argv[])
{
    cout << "input " << semesterTotal << " scores: ";
    sum = 0;

    for (int i = 0; i < semesterTotal; i++)
    {
        cin >> score[i];
        if (score[i] >= 80)
        {
            scoreLetter[i] = 'A';
            ip[i] = 4;
        }
        else if (score[i] >= 70)
        {
            scoreLetter[i] = 'B';
            ip[i] = 3;
        }
        else if (score[i] >= 60)
        {
            scoreLetter[i] = 'C';
            ip[i] = 2;
        }
        else if (score[i] >= 50)
        {
            scoreLetter[i] = 'D';
            ip[i] = 1;
        }
        else
        {
            scoreLetter[i] = 'E';
            ip[i] = 0;
        }
        sum += ip[i];
    }

    ipk = sum / semesterTotal;

    cout << fixed << showpoint << setprecision(2) << ipk << endl
         << (ipk >= 2.75 ? "LULUS" : "TIDAK LULUS") << endl;
}
