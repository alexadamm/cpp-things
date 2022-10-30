#include <iostream>
#include <math.h>
using namespace std;

struct vector {
    float i;
    float j;
    float k;
};

// Vector length function of a vector by using a vector as the parameter
float vectorLength(vector v) {
    return sqrt(pow(v.i, 2) + pow(v.j, 2) + pow(v.k, 2));
}

// Vector sum function of two vectors by using two vectors as the parameters
struct vector vectorAdd(vector v1, vector v2) {
    struct vector v3;
    v3.i = v1.i + v2.i;
    v3.j = v1.j + v2.j;
    v3.k = v1.k + v2.k;
    return v3;
}

// Dot product function of two vectors by using two vectors as parameters
float vectorDotProduct(vector A, vector B) {
    return (A.i * B.i) + (A.j * B.j) + (A.k * B.k);
}

// Vector angle function of two vectors by using two vectors as parameters
float vectorAngle(vector A, vector B) {
    return acos((A.i * B.i + A.j * B.j + A.k * B.k) / (vectorLength(A) * vectorLength(B))) * 180/M_PI;
}

// Cross product function of two vectors by using two vectors as parameters
struct vector vectorCrossProduct(vector A, vector B) {
    struct vector C;
    C.i = A.j * B.k - A.k * B.j;
    C.j = A.k * B.i - A.i * B.k;
    C.k = A.i * B.j - A.j * B.i;
    return C;
}

// Vector projection function to find the projection of vector A onto vector B bt using two vectors as parameters
struct vector vectorProjection(vector A, vector B) {
    struct vector C;
    C.i = vectorDotProduct(A, B) / pow(vectorLength(B), 2) * B.i;
    C.j = vectorDotProduct(A, B) / pow(vectorLength(B), 2) * B.j;
    C.k = vectorDotProduct(A, B) / pow(vectorLength(B), 2) * B.k;
    return C;
}

void vectorInput(vector& V, string name) {
    cout << "Enter the vector " << name << " length x side: ";
    cin >> V.i;
    cout << "Enter the vector " << name << " length y side: ";
    cin >> V.j;
    cout << "Enter the vector " << name << " length z side: ";
    cin >> V.k;
    cout << endl;
}

void operationScreen(vector& A, vector& B, string name) {
    cout << endl << "----------------- " << name << " -----------------" << endl;
    vectorInput(A, "A");
    vectorInput(B, "B");
}

void start(vector A, vector B, vector C) {
    cout << endl << "----------------- Vector Operations -----------------" << endl;
    cout << "1. Vector Length" << endl;
    cout << "2. Vector Addition" << endl;
    cout << "3. Vector Angle" << endl;
    cout << "4. Vector Dot Product" << endl;
    cout << "5. Vector Cross Product" << endl;
    cout << "6. Vector Projection" << endl;
    cout << "0. Exit" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << endl << "----------------- Vector Length -----------------" << endl;
        vectorInput(A, "A");
        cout << "The length of the vector is: " << vectorLength(A) << endl;
        break;
    case 2:
        operationScreen(A, B, "Vector Addition");
        C = vectorAdd(A, B);
        cout << "The vector A + B is: " << C.i << "i + " << C.j << "j + " << C.k << "k" << endl;
        break;
    case 3:
        operationScreen(A, B, "Vector Angle");
        cout << "The angle between vector A and B is: " << vectorAngle(A, B) << "°" << endl;
        break;
    case 4:
        operationScreen(A, B, "Vector Dot Product");
        cout << "The dot product of vector A and B is: " << vectorDotProduct(A, B) << endl;
        break;
    case 5:
        operationScreen(A, B, "Vector Cross Product");
        C = vectorCrossProduct(A, B);
        cout << "The cross product of vector A and B is: " << C.i << "i + " << C.j << "j + " << C.k << "k" << endl;
        break;
    case 6:
        operationScreen(A, B, "Vector Projection");
        C = vectorProjection(A, B);
        cout << "The projection of vector A on B is: " << C.i << "i + " << C.j << "j + " << C.k << "k" << endl;
        break;
    case 0:
        cout << "Exiting..." << endl;
        exit(0);
        break;
    default:
        cout << "Invalid choice" << endl;
    }
}

int main(int argc, char const *argv[])
{
    struct vector A, B, C;
    // Game
    while(true) {
        start(A, B, C);
    }
}
