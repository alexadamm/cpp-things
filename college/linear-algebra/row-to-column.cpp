#include <iostream>
#include <json/value.h>
#include <json/json.h>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

vector<vector<double>> getData()
{
    ifstream file("pca-data.json");
    Json::Value actualJson;
    Json::Reader reader;

    reader.parse(file, actualJson);

    vector<vector<double>> data(actualJson["data"].size(), vector<double>(actualJson["data"][0].size()));
    for (int i = 0; i < actualJson["data"].size(); i++)
    {
        for (int j = 0; j < actualJson["data"][i].size(); j++)
        {
            data[i][j] = actualJson["data"][i][j].asDouble();
        }
    }

    return data;
}

int main(int argc, char const *argv[])
{
    vector<vector<double>> data = getData();

    cout << "[" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "[" << endl;
        for (int j = 0; j < 4; j++)
        {
            cout << data[j][i] << ", ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
    return 0;
}
