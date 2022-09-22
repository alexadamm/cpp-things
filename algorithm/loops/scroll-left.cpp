#include <iostream>
using namespace std;

string word, store;

int main(int argc, char const *argv[])
{
    cout << "input initial banner: " << endl;
    getline(cin, word, '\n');
    store = word;
    for (int i = 0; i <= word.length() - 1; i++)
    {
        for (int j = 1; j <= word.length() - 1; j++)
        {
            store[j - 1] = word[j];
        }
        store[word.length() - 1] = word[0];
        word = store;

        cout << store << endl;
    }
    return 0;
}

// 01234
// 12340
// 23401
// 34012
// 40123
// 01234
