#include <iostream>
using namespace std;

struct student
{
    int id;
    string name;
    int score;
};

int sequentialSearchById(student students[], int size, int id)
{
    for (int i = 0; i < size; i++)
    {
        if (students[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

int binarySearchById(student students[], int size, int id)
{
    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (students[mid].id == id)
        {
            return mid;
        }
        else if (students[mid].id < id)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

void printData(student data)
{
    cout << "ID: " << data.id << endl;
    cout << "Name: " << data.name << endl;
    cout << "Score: " << data.score << endl;
}

int main(int argc, char const *argv[])
{
    student students[7];
    students[0].id = 12340;
    students[1].id = 12341;
    students[2].id = 12342;
    students[3].id = 12343;
    students[4].id = 12345;
    students[5].id = 12346;
    students[6].id = 12347;

    students[0].name = "Handi Ramadhan";
    students[1].name = "Rio Alfandra";
    students[2].name = "Ronaldo Valentino Uneputty";
    students[3].name = "Achmad Yaumil Fadjri R.";
    students[4].name = "Alivia Rahma Pramesti";
    students[5].name = "Ari Lutfianto";
    students[6].name = "Arief Budiman";

    students[0].score = 95;
    students[1].score = 55;
    students[2].score = 80;
    students[3].score = 60;
    students[4].score = 70;
    students[5].score = 65;
    students[6].score = 60;

    int id;
    cout << "----------- Sequential Search -------------" << endl;
    cout << "Input ID to search: ";
    cin >> id;

    int index = sequentialSearchById(students, 7, id);
    if (index == -1)
        cout << "Element not found" << endl;
    else
    {
        printData(students[index]);
        cout << "--------------------------------" << endl;
        cout << "Input new name: ";
        cin.ignore();
        getline(cin, students[index].name);
        cout << "Input new score: ";
        cin >> students[index].score;
        cout << "--------------------------------" << endl;
        cout << "Updated Data: " << endl;
        printData(students[index]);
    }
    cout << "----------- Binary Search -------------" << endl;
    cout << "Input ID to search: ";
    cin >> id;
    index = binarySearchById(students, 7, id);
    if (index == -1)
        cout << "Element not found" << endl;
    else
    {
        printData(students[index]);
        cout << "--------------------------------" << endl;
        cout << "Input new name: ";
        cin.ignore();
        getline(cin, students[index].name);
        cout << "Input new score: ";
        cin >> students[index].score;
        cout << "--------------------------------" << endl;
        cout << "Updated Data: " << endl;
        printData(students[index]);
    }
}
