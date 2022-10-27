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
    return acos((A.i * B.i + A.j * B.j + A.k * B.k) / (vectorLength(A) * vectorLength(B)));
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
    C.i = vectorDotProduct(A, B) / sqrt(vectorLength(B)) * B.i;
    C.j = vectorDotProduct(A, B) / sqrt(vectorLength(B)) * B.j;
    C.k = vectorDotProduct(A, B) / sqrt(vectorLength(B)) * B.k;
    return C;
}

int start(vector A, vector B, vector C) {
    cout << "----------------- Vector Operations -----------------" << endl;
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
        cout << "Enter the vector length x side: ";
        cin >> A.i;
        cout << "Enter the vector length y side: ";
        cin >> A.j;
        cout << "Enter the vector length z side: ";
        cin >> A.k;
        cout << "The length of the vector is: " << vectorLength(A) << endl << endl;
        break;
    case 2:
        cout << endl << "----------------- Vector Addition -----------------" << endl;
        cout << "Enter the vector A x side: ";
        cin >> A.i;
        cout << "Enter the vector A y side: ";
        cin >> A.j;
        cout << "Enter the vector A z side: ";
        cin >> A.k;
        cout << endl;
        cout << "Enter the vector B x side: ";
        cin >> B.i;
        cout << "Enter the vector B y side: ";
        cin >> B.j;
        cout << "Enter the vector B z side: ";
        cin >> B.k;
        cout << endl; 
        C = vectorAdd(A, B);
        cout << endl << "The vector A + B is: " << C.i << "i + " << C.j << "j + " << C.k << "k" << endl << endl;
        break;
    case 3:
        cout << endl << "----------------- Vector Angle -----------------" << endl;
        cout << "Enter the vector A x side: ";
        cin >> A.i;
        cout << "Enter the vector A y side: ";
        cin >> A.j;
        cout << "Enter the vector A z side: ";
        cin >> A.k;
        cout << endl; 
        cout << "Enter the vector B x side: ";
        cin >> B.i;
        cout << "Enter the vector B y side: ";
        cin >> B.j;
        cout << "Enter the vector B z side: ";
        cin >> B.k;
        cout << endl; 
        cout << endl << "The angle between vector A and B is: " << vectorAngle(A, B) << " radians" << endl << endl;
        break;
    case 4:
        cout << endl << "----------------- Vector Dot Product -----------------" << endl;
        cout << "Enter the vector A x side: ";
        cin >> A.i;
        cout << "Enter the vector A y side: ";
        cin >> A.j;
        cout << "Enter the vector A z side: ";
        cin >> A.k;
        cout << endl; 
        cout << "Enter the vector B x side: ";
        cin >> B.i;
        cout << "Enter the vector B y side: ";
        cin >> B.j;
        cout << "Enter the vector B z side: ";
        cin >> B.k;
        cout << endl;
        cout << endl << "The dot product of vector A and B is: " << vectorDotProduct(A, B) << endl << endl;
        break;
    case 5:
        cout << endl << "----------------- Vector Cross Product -----------------" << endl;
        cout << "Enter the vector A x side: ";
        cin >> A.i;
        cout << "Enter the vector A y side: ";
        cin >> A.j;
        cout << "Enter the vector A z side: ";
        cin >> A.k;
        cout << endl; 
        cout << "Enter the vector B x side: ";
        cin >> B.i;
        cout << "Enter the vector B y side: ";
        cin >> B.j;
        cout << "Enter the vector B z side: ";
        cin >> B.k;
        cout << endl;
        C = vectorCrossProduct(A, B);
        cout << endl << "The cross product of vector A and B is: " << C.i << "i + " << C.j << "j + " << C.k << "k" << endl << endl;
        break;
    case 6:
        cout << endl << "----------------- Vector Projection -----------------" << endl;
        cout << "Enter the vector A x side: ";
        cin >> A.i;
        cout << "Enter the vector A y side: ";
        cin >> A.j;
        cout << "Enter the vector A z side: ";
        cin >> A.k;
        cout << endl; 
        cout << "Enter the vector B x side: ";
        cin >> B.i;
        cout << "Enter the vector B y side: ";
        cin >> B.j;
        cout << "Enter the vector B z side: ";
        cin >> B.k;
        cout << endl;
        C = vectorProjection(A, B);
        cout << endl << "The projection of vector A on B is: " << C.i << "i + " << C.j << "j + " << C.k << "k" << endl << endl;
        break;
    case 0:
        cout << "Exiting..." << endl;
        exit(0);
        break;
    default:
        cout << "Invalid choice" << endl;
        break;    
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    struct vector A, B, C;
    // Game
    while(true) {
        start(A, B, C);
    }
}
