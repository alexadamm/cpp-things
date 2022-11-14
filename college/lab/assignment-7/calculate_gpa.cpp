#include <iostream>
using namespace std;

int calculate_gpa(int n, char score[], int sks[]) {
    int tmp[n];
    int numerator = 0;
    int denominator = 0;
    
    for (int i = 0; i < n; i++) {
        if (score[i] == 'A') {
            tmp[i] = 4 * sks[i];
        }
        else if (score[i] == 'B') {
            tmp[i] = 3 * sks[i];
        }
        else if (score[i] == 'C') {
            tmp[i] = 2 * sks[i];
        }
        else if (score[i] == 'D') {
            tmp[i] = 1 * sks[i];
        }
        else if (score[i] == 'E') {
            tmp[i] = 0 * sks[i];
        }
    }

    for (int i = 0; i < n; i++) {
        numerator += tmp[i];
    }

    for (int i = 0; i < n; i++) {
        denominator += sks[i];
    }
    return  numerator/denominator;
}

int main(int argc, char const *argv[])
{   
    int n;
    cout << "Enter the number of courses: ";
    cin >> n;
    char score[n];
    int sks[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the score of course " << i+1 << ": ";
        cin >> score[i];
        cout << "Enter the sks of course " << i+1 << ": ";
        cin >> sks[i];
    }

    cout << "Your GPA is " << calculate_gpa(n, score, sks) << endl;
    return 0;
}
