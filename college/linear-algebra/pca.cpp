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

double getMean(vector<double> var)
{
    double sum = 0;
    for (int i = 0; i < var.size(); i++)
    {
        sum += var[i];
    }

    return sum / (double)var.size();
}

double getStandardDeviation(vector<double> var)
{
    double mean = getMean(var);
    double sum = 0;
    for (int i = 0; i < var.size(); i++)
    {
        sum += pow(var[i] - mean, 2);
    }

    cout << "Standard Deviation: " << sqrt(sum / (double)(var.size() - 1)) << endl;

    return sqrt(sum / (double)(var.size() - 1));
}

void standarizeData(vector<vector<double>> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        double mean = getMean(data[i]);
        double std = getStandardDeviation(data[i]);
        for (int j = 0; j < data[i].size(); j++)
        {
            data[i][j] = (data[i][j] - mean) / std;
        }
    }
}

double getCov(vector<double> x, vector<double> y, int n)
{
    double xMean, yMean, numerator;
    xMean = getMean(x);
    yMean = getMean(y);
    numerator = 0;
    for (int i = 0; i < n; i++)
    {
        numerator += (x[i] - xMean) * (y[i] - yMean);
    }

    return numerator / (double)n;
}

vector<vector<double>> getCovarianceMatrix(vector<vector<double>> data)
{
    vector<vector<double>> covarianceMatrix(data.size(), vector<double>(data.size()));
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data.size(); j++)
        {
            covarianceMatrix[i][j] = getCov(data[i], data[j], data[i].size());
        }
    }

    return covarianceMatrix;
}

vector<vector<double>> matrixSum(vector<vector<double>> a, vector<vector<double>> b)
{
    vector<vector<double>> sum(a.size(), vector<double>(a.size()));
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    return sum;
}

double getDeterminant(vector<vector<double>> matrix)
{
    double determinant = 0;
    if (matrix.size() == 1)
    {
        return matrix[0][0];
    }
    else if (matrix.size() == 2)
    {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            vector<vector<double>> subMatrix(matrix.size() - 1, vector<double>(matrix.size() - 1));
            for (int j = 1; j < matrix.size(); j++)
            {
                for (int k = 0; k < matrix.size(); k++)
                {
                    if (k < i)
                    {
                        subMatrix[j - 1][k] = matrix[j][k];
                    }
                    else if (k > i)
                    {
                        subMatrix[j - 1][k - 1] = matrix[j][k];
                    }
                }
            }
            determinant += pow(-1, i) * matrix[0][i] * getDeterminant(subMatrix);
        }
    }

    return determinant;
}

vector<vector<double>> getAdjoint(vector<vector<double>> matrix)
{
    vector<vector<double>> adjoint(matrix.size(), vector<double>(matrix.size()));
    if (matrix.size() == 1)
    {
        adjoint[0][0] = 1;
        return adjoint;
    }
    else
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                vector<vector<double>> subMatrix(matrix.size() - 1, vector<double>(matrix.size() - 1));
                for (int k = 0; k < matrix.size(); k++)
                {
                    for (int l = 0; l < matrix.size(); l++)
                    {
                        if (k < i && l < j)
                        {
                            subMatrix[k][l] = matrix[k][l];
                        }
                        else if (k < i && l > j)
                        {
                            subMatrix[k][l - 1] = matrix[k][l];
                        }
                        else if (k > i && l < j)
                        {
                            subMatrix[k - 1][l] = matrix[k][l];
                        }
                        else if (k > i && l > j)
                        {
                            subMatrix[k - 1][l - 1] = matrix[k][l];
                        }
                    }
                }
                adjoint[j][i] = pow(-1, i + j) * getDeterminant(subMatrix);
            }
        }
    }

    return adjoint;
}

vector<vector<double>> getInverse(vector<vector<double>> matrix)
{
    vector<vector<double>> inverse(matrix.size(), vector<double>(matrix.size()));
    double determinant = getDeterminant(matrix);
    vector<vector<double>> adjoint = getAdjoint(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            inverse[i][j] = adjoint[i][j] / determinant;
        }
    }

    return inverse;
}

vector<double> getEigenValues(vector<vector<double>> covarianceMatrix)
{
    vector<vector<double>> eigenValueMatrix(data.size());
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data.size(); j++)
        {
            eigenValueMatrix[i][j] = (i == j) ? -1 : 0;
        }
    }

    return eigenValues;
}

void printData(vector<vector<double>> data)
{
    for (int i = 0; i < data.size(); i++)
    {
        cout << "variable " << i + 1 << ": " << endl;
        for (int j = 0; j < data[i].size(); j++)
        {
            cout << j + 1 << " ";
            cout << data[i][j] << endl;
        }
        cout << "mean: " << getMean(data[i]) << endl;
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    // Clear
    vector<vector<double>> data = getData();
    printData(data);

    // Clear
    standarizeData(data);
    printData(data);

    cout << "Covariance matrix: " << endl;
    vector<vector<double>> covarianceMatrix = getCovarianceMatrix(data);
    print(covarianceMatrix);
}
