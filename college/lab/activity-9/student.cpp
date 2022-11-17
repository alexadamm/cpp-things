#include <iostream>
using namespace std;

struct Student
{
    int id;
    string name;
    int score;
    int homeDistance;
} students[7];

void insertionSortByStudentId()
{
    int tempId, j;
    string tempName;
    int tempScore, tempHomeDistance;

    for (int i = 1; i < 7; i++)
    {
        tempId = students[i].id;
        tempName = students[i].name;
        tempScore = students[i].score;
        tempHomeDistance = students[i].homeDistance;
        j = i - 1;

        while (j >= 0 && students[j].id > tempId)
        {
            students[j + 1].id = students[j].id;
            students[j + 1].name = students[j].name;
            students[j + 1].score = students[j].score;
            students[j + 1].homeDistance = students[j].homeDistance;
            j--;
        }

        students[j + 1].id = tempId;
        students[j + 1].name = tempName;
        students[j + 1].score = tempScore;
        students[j + 1].homeDistance = tempHomeDistance;
    }
}

void selectionSortByStudentScore()
{
    int minIndex, tempId, tempScore, tempHomeDistance;
    string tempName;

    for (int i = 0; i < 6; i++)
    {
        minIndex = i;

        for (int j = i + 1; j < 7; j++)
        {
            if (students[j].score > students[minIndex].score)
            {
                minIndex = j;
            }
        }

        tempId = students[minIndex].id;
        tempName = students[minIndex].name;
        tempScore = students[minIndex].score;
        tempHomeDistance = students[minIndex].homeDistance;

        students[minIndex].id = students[i].id;
        students[minIndex].name = students[i].name;
        students[minIndex].score = students[i].score;
        students[minIndex].homeDistance = students[i].homeDistance;

        students[i].id = tempId;
        students[i].name = tempName;
        students[i].score = tempScore;
        students[i].homeDistance = tempHomeDistance;
    }
}

void bubbleSortByHomeDistance()
{
    int tempId, tempScore, tempHomeDistance;
    string tempName;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (students[j].homeDistance < students[j + 1].homeDistance)
            {
                tempId = students[j].id;
                tempName = students[j].name;
                tempScore = students[j].score;
                tempHomeDistance = students[j].homeDistance;

                students[j].id = students[j + 1].id;
                students[j].name = students[j + 1].name;
                students[j].score = students[j + 1].score;
                students[j].homeDistance = students[j + 1].homeDistance;

                students[j + 1].id = tempId;
                students[j + 1].name = tempName;
                students[j + 1].score = tempScore;
                students[j + 1].homeDistance = tempHomeDistance;
            }
        }
    }
}
int main(int argc, char const *argv[])
{

    students[0].id = 96031;
    students[0].name = "Handi Ramadhan";
    students[0].score = 90;
    students[0].homeDistance = 1000;

    students[1].id = 96395;
    students[1].name = "Rio Alfandra";
    students[1].score = 55;
    students[1].homeDistance = 6000;

    students[2].id = 95031;
    students[2].name = "Ronaldo Valentino Uneputty";
    students[2].score = 80;
    students[2].homeDistance = 7500;

    students[3].id = 97027;
    students[3].name = "Achman Yaumil Fadjri R.";
    students[3].score = 60;
    students[3].homeDistance = 2500;

    students[4].id = 97029;
    students[4].name = "Alivia Rahma Pramesti";
    students[4].score = 70;
    students[4].homeDistance = 10000;

    students[5].id = 95238;
    students[5].name = "Ari Lutfianto";
    students[5].score = 65;
    students[5].homeDistance = 4000;

    students[6].id = 96565;
    students[6].name = "Arief Buriman";
    students[6].score = 60;
    students[6].homeDistance = 2000;

    cout << endl
         << "Insertion Sort by Student Id" << endl
         << endl;
    insertionSortByStudentId();

    for (int i = 0; i < 7; i++)
    {
        cout << students[i].id << " " << students[i].name << " " << students[i].score << " " << students[i].homeDistance << endl;
    }

    cout << endl
         << "Selection Sort by Student Score" << endl
         << endl;
    selectionSortByStudentScore();

    for (int i = 0; i < 7; i++)
    {
        cout << students[i].id << " " << students[i].name << " " << students[i].score << " " << students[i].homeDistance << endl;
    }

    cout << endl
         << "Bubble Sort By Home Distance" << endl
         << endl;
    bubbleSortByHomeDistance();

    for (int i = 0; i < 7; i++)
    {
        cout << students[i].id << " " << students[i].name << " " << students[i].score << " " << students[i].homeDistance << endl;
    }
    return 0;
}
