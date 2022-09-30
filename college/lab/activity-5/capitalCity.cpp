#include <iostream>
using namespace std;
string country;
string capital[5][2] = {
    {"Indonesia", "Jakarta"},
    {"Filipina", "Manila"},
    {"Austria", "Vienna"},
    {"India", "New Delhi"},
    {"Iran", "Taheran"}
    };

int main(int argc, char const *argv[])
{
    cout << "Enter the country name: ";
    cin >> country;
    for (int i = 0; i < 5; i++)
    {
        if (capital[i][0] == country)
        {
            cout << capital[i][1] << endl;
        }
    }
    return 0;
}
