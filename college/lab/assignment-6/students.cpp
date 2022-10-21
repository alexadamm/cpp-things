#include <iostream>
using namespace std;

struct Student {
    string id;
    double midterm_score;
    double finalexam_score;
};

double total_score;

double score_rate;

int n;

int main(int argc, char const *argv[])
{
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    
    if (n > 50) n=50;

    Student students[n];

    for (int i = 0; i<n; i++) {
        cout << "Mahasiswa " << i+1 << endl;
        cout << "Masukkan ID mahasiswa: ";
        cin >> students[i].id;
        cout << "Nilai UTS: ";
        cin >> students[i].midterm_score;
        cout << "Nilai UAS: ";
        cin >> students[i].finalexam_score;
        cout << endl;
    }

    for (int i = 0; i<n; i++) {
        total_score = students[i].midterm_score + students[i].finalexam_score;
        score_rate = total_score / 2;
        cout << "ID Mahasiswa: " << students[i].id << endl << "Rata-rata: " << score_rate << endl;
    }

    return 0;
}
