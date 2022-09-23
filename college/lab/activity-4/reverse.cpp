#include <iostream>
using namespace std;

string word;

int main(int argc, char const *argv[])
{
    cin >> word;

    for (int i = word.length() - 1; i >= 0; i--)
    {
        cout << word[i];
    }
    cout << endl;
    return 0;
}
