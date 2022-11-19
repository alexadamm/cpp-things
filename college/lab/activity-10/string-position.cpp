#include <iostream>
using namespace std;

int posstr(string str, string search)
{
    int n = str.size(), m = search.size();
    for (int i = 0, j = 0; i < n; i++)
    {
        if (str[i] != search[j])
            j = 0;
        j = (str[i] == search[j]) ? j + 1 : 0;
        if (j == m)
            return i - m + 1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    string str, search;
    cin >> str;
    cin >> search;
    cout << posstr(str, search) << endl;
}
