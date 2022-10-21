#include <iostream>
using namespace std;

struct Person {
    int month;
    int day;
    string zodiac;
};

bool isValidDate(int m, int d)
{
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > 31)
        return false;
    if (m == 2 && d > 28)
        return false;
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
        return false;
    return true;
}

string zodiac(int m, int d)
{
    if (m == 1)
        return (d >= 20) ? "Aquarius" : "Capricorn";
    else if (m == 2)
        return (d >= 19) ? "Pisces" : "Aquarius";
    else if (m == 3)
        return (d >= 21) ? "Aries" : "Pisces";
    else if (m == 4)
        return (d >= 20) ? "Taurus" : "Aries";
    else if (m == 5)
        return (d >= 21) ? "Gemini" : "Taurus";
    else if (m == 6)
        return (d >= 21) ? "Cancer" : "Gemini";
    else if (m == 7)
        return (d >= 23) ? "Leo" : "Cancer";
    else if (m == 8)
        return (d >= 23) ? "Virgo" : "Leo";
    else if (m == 9)
        return (d >= 23) ? "Libra" : "Virgo";
    else if (m == 10)
        return (d >= 23) ? "Scorpio" : "Libra";
    else if (m == 11)
        return (d >= 22) ? "Sagittarrius" : "Scorpio";
    else
        return (d >= 22) ? "Capricorn" : "Sagittarius";
}

int main(int argc, char const *argv[])
{
    struct Person person;

    cout << "Enter month: ";
    cin >> person.month;
    cout << "Enter day: ";
    cin >> person.day;

    person.zodiac = zodiac(person.month, person.day);

    (isValidDate(person.month, person.day)) ? cout << "your zodiac is " << person.zodiac << endl
                               : cout << "invalid input!" << endl;
    return 0;
}

